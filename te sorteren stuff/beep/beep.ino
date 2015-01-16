#define DELAY_OFFSET 11
#define BEEP_PIN 0
// declare it for good measure
void beep(unsigned long hz, unsigned long ms);
void setup() {
pinMode(BEEP_PIN, OUTPUT);
}
void loop() {
beep(1500, 250);
delay(750);
}
void beep(unsigned long hz, unsigned long ms) {
// reference: 440hz = 2273 usec/cycle, 1136 usec/half-cycle
unsigned long us = (500000 / hz) - DELAY_OFFSET;
unsigned long rep = (ms * 500L) / (us + DELAY_OFFSET);
for (int i = 0; i < rep; i++) {
digitalWrite(BEEP_PIN, HIGH);
delayMicroseconds(us);
digitalWrite(BEEP_PIN, LOW);
delayMicroseconds(us);
}
}
