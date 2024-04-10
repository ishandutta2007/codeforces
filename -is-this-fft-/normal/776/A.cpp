#include <iostream>
#include <string>

using namespace std;

int main () {
  string a, b;
  cin >> a >> b;
  
  int dayc;
  cin >> dayc;
  
  cout << a << " " << b << endl;
  for (int i = 0; i < dayc; i++) {
    string killed, newguy;
    cin >> killed >> newguy;

    if (killed == a) {
      a = newguy;
    } else {
      b = newguy;
    }

    cout << a << " " << b << endl;
  }
}