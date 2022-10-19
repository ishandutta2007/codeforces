#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;

ll pows(ll x, ll y = MOD - 2) {
  ll ret = 1;
  while (y) {
    if (y & 1)
      ret = ret * x % MOD;
    x = x * x % MOD;
    y >>= 1;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<ll> p(1000001), invp(10000001);
  p[0] = invp[0] = 1;
  for (int i = 1; i <= 1000000; i++) {
    p[i] = p[i - 1] * i % MOD;
    invp[i] = pows(p[i]);
  }
  auto C = [&](int n, int m) {
    return p[n] * invp[m] % MOD * invp[n - m] % MOD;
  };

  int n;
  cin >> n;
  ll ans = 0;
  for (int i = 0; i <= n; i++) {
    int k;
    cin >> k;
    if (k == 0)
      continue;
    ans = (ans + C(k + i, i + 1)) % MOD;
  }
  cout << ans << '\n';
}