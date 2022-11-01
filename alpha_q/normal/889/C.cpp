#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1000005;
const int MOD = 1e9 + 7;

int n, k;
ll fac[N];
ll inv[N];
ll f[N];
ll sum[N];

ll bigMod (ll a, int e) {
  ll r = 1;
  while (e) {
    if (e & 1) {
      r = (r * a) % MOD;
    }
    a = (a * a) % MOD;
    e >>= 1;
  }
  return r;
}

ll get (int l, int r) {
  l = max(l, 1);
  return sum[r] - sum[l - 1];
}

int main() {
  scanf("%d %d", &n, &k);
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) {
    fac[i] = i * 1LL * fac[i - 1] % MOD;
  }
  inv[n] = bigMod(fac[n], MOD - 2);
  for (int i = n - 1; i >= 0; --i) {
    inv[i] = (i + 1) * 1LL * inv[i + 1] % MOD;
  }
  for (int i = k + 2; i <= n; ++i) {
    f[i] = i - k - 1 + get(i - k, i - 1);
    f[i] *= fac[i - 2], f[i] %= MOD;
    sum[i] = (sum[i - 1] + f[i] * inv[i - 1]) % MOD;
  }
  ll ans = (sum[n] * fac[n - 1]) % MOD;
  if (ans < 0) ans += MOD;
  printf("%lld\n", ans);
  return 0;
}