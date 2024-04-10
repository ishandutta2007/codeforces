#include <iostream>

using namespace std;

typedef long long ll;

void solve () {
  ll x;
  cin >> x;

  ll ev = 1;
  while (x % 2 == 0) {
    ev *= 2;
    x /= 2;
  }

  if (x == 1) {
    cout << -1 << '\n';
  } else {
    cout << min(x, 2 * ev) << '\n';
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