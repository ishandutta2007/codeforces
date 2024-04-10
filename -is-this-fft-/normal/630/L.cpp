#include <iostream>

using namespace std;

int digits [5];

int main () {
  char c;
  for (int i = 0; i < 5; i++) {
    cin >> c;
    digits[i] = c - '0';
  }

  int base = (digits[0] * 10000 +
	      digits[2] * 1000 +
	      digits[4] * 100 +
	      digits[3] * 10 +
	      digits[1] * 1);
  long long ans = 1;
  for (int i = 0; i < 5; i++) {
    ans *= base;
    ans %= 100000;
  }

  if (ans < 10) cout << "0000";
  else if (ans < 100) cout << "000";
  else if (ans < 1000) cout << "00";
  else if (ans < 10000) cout << "0";
  cout << ans << endl;
}