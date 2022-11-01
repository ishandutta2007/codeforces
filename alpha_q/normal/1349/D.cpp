#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 300010;
const int MOD = 998244353;

ll bigMod (ll a, ll e) {
  if (e == -1) e = MOD - 2;
  ll ret = 1;
  while (e) {
    if (e & 1) ret = ret * a % MOD;
    a = a * a % MOD, e >>= 1;
  }
  return ret;
}

int n; ll a[N], f[N];

int main() {
  cin >> n;
  ll tot = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", a + i);
    tot += a[i];
  }
  for (ll i = 0; i < tot; ++i) {
    ll one = (tot + i * (n - 2)) % MOD;
    one = one * bigMod(tot - i, -1) % MOD;
    one = one * f[i] % MOD;
    ll two = i * (n - 1) % MOD;
    two = two * bigMod(tot - i, -1) % MOD;
    if (i) two = two * (1 + f[i - 1]) % MOD;
    f[i + 1] = (one - two + MOD) % MOD;
  }
  ll ans = 0;
  for (int i = 1; i <= n; ++i) ans += f[a[i]], ans %= MOD;
  ans -= (n - 1) * f[0] + f[tot], ans %= MOD;
  ans += MOD, ans %= MOD;
  cout << ans << '\n';
  return 0;
}