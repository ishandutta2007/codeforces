#include <iostream>

using namespace std;

int main () {
  int length, divisor;
  cin >> length >> divisor;

  if (divisor == 10) {
    if (length == 1) {
      cout << -1 << endl;
    } else {
      cout << 1;
      for (int i = 1; i < length; i++) {
	cout << 0;
      }
      cout << endl;
    }
  } else {
    for (int i = 0; i < length; i++) {
      cout << divisor;
    }
    cout << endl;
  }
}