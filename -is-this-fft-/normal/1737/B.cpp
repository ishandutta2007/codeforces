#include <iostream>

using namespace std;

typedef long long ll;

ll cnt (ll r) {
  ll tot = 0;
  for (ll add = 0; add <= 2; add++) {
    ll ans = 0;
    for (ll k = 1 << 30; k != 0; k /= 2) {
      ll cur = ans + k;
      if (cur * (cur + add) <= r) {
        ans += k;
      }
    }
    tot += ans;
  }

  return tot;
}

void solve () {
  ll l, r;
  cin >> l >> r;

  cout << cnt(r) - cnt(l - 1) << '\n';
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