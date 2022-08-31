#include <iostream>

using namespace std;

void solve () {
  int c, d;
  cin >> c >> d;

  if (c % 2 != d % 2) {
    cout << -1 << '\n';
  } else if (c == 0 && d == 0) {
    cout << 0 << '\n';
  } else if (c == d) {
    cout << 1 << '\n';
  } else {
    cout << 2 << '\n';
  }
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}