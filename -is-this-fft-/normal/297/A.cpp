#include <iostream>

using namespace std;

int main () {
  string a, b;
  cin >> a >> b;

  int ioc = 0;
  for (char c : a) {
    if (c == '1') {
      ioc++;
    }
  }
  if (ioc % 2 == 1) {
    ioc++;
  }

  int foc = 0;
  for (char c : b) {
    if (c == '1') {
      foc++;
    }
  }

  if (foc <= ioc) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
  }
}