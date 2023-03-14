#define SS_PIN 5  
#define RST_PIN 4 

#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h> 

MFRC522 mfrc522(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27,20,4);


void setup() 
{
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  lcd.init(); 
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("WELCOME 2 FRESH MART");
  lcd.setCursor(0,1);
  lcd.print("PLACE YOUR CARD HERE");
  lcd.setCursor(0,2);
  lcd.print("NO U- CARD DETECTED ");
  lcd.setCursor(0,3);
  lcd.print("THANK U FOR VISIING");
  Serial.printf("started");
  
}
void loop() 
{
  int amount;
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
      while (Serial.available() > 0) {
      int amt=Serial.parseInt();
      amount = amt;
      lcd.setCursor(10,2);
      lcd.cursor_on();
      lcd.print(amount);
      lcd.setCursor(0,3);
      lcd.print("payment is sucessful");
      delay(2000);
      lcd.setCursor(0,1);
      lcd.print("PLACE YOUR CARD HERE");
      lcd.setCursor(0,2);
      lcd.print("NO U- CARD DETECTED ");
      lcd.setCursor(0,3);
      lcd.print("THANK U FOR VISIING ");
    }
    return;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  content.toUpperCase();
  if (content.substring(1) == "93 EE 8E 11") 
  {
    
    lcd.setCursor(0,1);
    lcd.print(" DEAR USER 1 PLEASE ");
    lcd.setCursor(0,2);
    lcd.print("ENTER AMT=          ");
    lcd.setCursor(0,3);
    lcd.print("                    ");
   
  }
  
} 
