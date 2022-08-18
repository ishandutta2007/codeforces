#include <iostream>

using namespace std;

bool solve () {
  int a, b, c;
  cin >> a >> b >> c;

  int sum = a + b + c;
  if (sum % 9 != 0) {
    return false;
  }

  int cnt = sum / 9;
  a -= cnt;
  b -= cnt;
  c -= cnt;
  if (a < 0 || b < 0 || c < 0) return false;

  if ((a + b + c) % 6 != 0) return false;
  return true;
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    auto ans = solve();
    cout << (ans ? "YES" : "NO") << '\n';
  }
}