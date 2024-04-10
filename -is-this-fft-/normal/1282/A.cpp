#include <iostream>

using namespace std;

typedef long long ll;

void solve () {
  ll a, b, c, r;
  cin >> a >> b >> c >> r;

  if (a > b) {
    swap(a, b);
  }

  ll ans = b - a;
  a = max(a, c - r);
  b = min(b, c + r);

  cout << ans - max(0LL, b - a) << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}