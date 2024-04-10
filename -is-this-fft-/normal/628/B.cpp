#include <iostream>
#include <string>

using namespace std;

bool goodsuf (char a, char b) {
  int num = a - '0';
  num *= 10;
  num += b - '0';
  return (num % 4 == 0);
}

int main () {
  ios::sync_with_stdio(false);

  string calc;
  cin >> calc;

  long long ans = 0;
  for (int i = 0; i < calc.size(); i++) {
    if (calc[i] == '0' || calc[i] == '4' || calc[i] == '8') {
      ans++;
    }
    if (i > 0) {
      if (goodsuf(calc[i - 1], calc[i])) {
	ans += i;
      }
    }
  }

  cout << ans << endl;
}