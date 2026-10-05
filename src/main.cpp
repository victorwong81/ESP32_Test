#include <Arduino.h>

#define LED_PIN 2

void setup() {
    pinMode(LED_PIN, OUTPUT);

    Serial.begin(115200);
    delay(1000);

    Serial.println();
    Serial.println("================================");
    Serial.println("       WELCOME TO ESP32");
    Serial.println("================================");
    Serial.println("ESP32 is ready!");
    Serial.println();
    Serial.println("Commands:");
    Serial.println("  ON  - Turn LED on");
    Serial.println("  OFF - Turn LED off");
    Serial.println("================================");
    Serial.println();
}

void loop() {

    if (Serial.available() > 0) {

        String command = Serial.readStringUntil('\n');
        command.trim();

        if (command == "ON") {
            digitalWrite(LED_PIN, HIGH);
            Serial.println("LED ON");
        }

        else if (command == "OFF") {
            digitalWrite(LED_PIN, LOW);
            Serial.println("LED OFF");
        }

        else {
            Serial.print("Unknown command: ");
            Serial.println(command);
        }
    }
}