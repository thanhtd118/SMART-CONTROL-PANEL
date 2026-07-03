#include<Wire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); 
String menu[] = {
  "LED",
  "RGB",
  "BUZZER"
};
int menuindex=0;
const int menucount = 3;
const int buttonUp = 2;
const int buttonDown = 3;
void hienthiGiaodien() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("SMART CONTROL");

  hienthiMenu();
}
void hienthiMenu() {
  lcd.setCursor(0, 1);

  // Xóa riêng dòng thứ 2
  lcd.print("                ");   

  lcd.setCursor(0, 1);
  lcd.print("> ");
  lcd.print(menu[menuindex]);
}
void setup()
{
  pinMode(buttonUp,INPUT_PULLUP);
  pinMode(buttonDown,INPUT_PULLUP);
  lcd.init();
  lcd.backlight();
  hienthiGiaodien();
}
void loop()
{
  docNutNhan();
}
void docNutNhan(){
  int trangthaiUp = digitalRead(buttonUp);
  int trangthaiDown = digitalRead(buttonDown);
  if(trangthaiUp == 0) {
    menuindex--;
  if(menuindex < 0) {
    menuindex = menucount - 1;
  }
  hienthiMenu();
  delay(200);
}
  else if(trangthaiDown == 0) {
    menuindex++;
  if (menuindex >= menucount) {
    menuindex = 0;
  }
  hienthiMenu();
  delay(200);
}
}
