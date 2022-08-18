#include <iostream>

using namespace std;

typedef long long ll;

void solve () {
  ll x, y;
  cin >> x >> y;

  if (x == y) {
    cout << x << '\n';
    return;
  }

  if (x < y) {
    ll rem = y % x;
    cout << y - rem / 2 << '\n';
    return;
  }

  cout << x + y << '\n';
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