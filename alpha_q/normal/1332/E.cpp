#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 998244353;
const ll INV = 1 + MOD >> 1;

ll bigMod (ll a, ll e) {
  ll ret = 1;
  while (e) {
    if (e & 1) ret = ret * a % MOD;
    a = a * a % MOD, e >>= 1;
  }
  return ret;
}

ll n, m, l, r;

int main() {
  cin >> n >> m >> l >> r;
  ll pwr = n * m, ev = (r / 2) - ((l - 1) / 2), od = r - l + 1 - ev;
  if (pwr & 1) {
    ll ans = bigMod((r - l + 1) % MOD, pwr);
    cout << ans << '\n';
    return 0;
  }
  ev %= MOD, od %= MOD;
  ll ans = bigMod((ev + od) % MOD, pwr) + bigMod((ev - od + MOD) % MOD, pwr);
  ans %= MOD, ans *= INV, ans %= MOD;
  cout << ans << '\n';  
  return 0;
}