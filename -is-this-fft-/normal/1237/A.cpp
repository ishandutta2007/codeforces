#include <iostream>

using namespace std;

int d2s (int x);

int d2b (int x) {
  if (x >= 0) 
    return (x + 1) / 2;
  else
    return -d2s(-x);
}

int d2s (int x) {
  if (x >= 0)
    return x / 2;
  else
    return -d2b(-x);
}

int main () {
  int length;
  cin >> length;

  int mode = 0;
  for (int i = 0; i < length; i++) {
    int x;
    cin >> x;

    if (x % 2 == 0) {
      cout << d2b(x) << '\n';
    } else {
      if (mode) {
        cout << d2s(x) << '\n';
      } else {
        cout << d2b(x) << '\n';
      }
      mode = !mode;
    }
  }    
}