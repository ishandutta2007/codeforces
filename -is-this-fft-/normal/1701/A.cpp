#include <iostream>

using namespace std;

void solve () {
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  int x = a + b + c + d;
  if (x == 0) {
    cout << 0 << '\n';
  } else if (x == 4) {
    cout << 2 << '\n';
  } else {
    cout << 1 << '\n';
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