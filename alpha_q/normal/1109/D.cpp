#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2000010;
const int MOD = 1e9 + 7;

ll bigMod (ll a, ll e) {
  if (e == -1) e = MOD - 2;
  ll ret = 1;
  while (e) {
    if (e & 1) ret = ret * a % MOD;
    a = a * a % MOD, e >>= 1;
  }
  return ret;
}

int n, m, a, b;
ll f[N], inv[N];

inline ll comb (int x, int y) {
  if (x < y or y < 0) return 0;
  return f[x] * (inv[y] * inv[x - y] % MOD) % MOD;
}

inline ll fn (ll comp) {
  ll res = comp * bigMod(n, n - comp - 1) % MOD;
  return res;
}

int main() {
  cin >> n >> m >> a >> b;
  f[0] = 1;
  for (int i = 1; i < N; ++i) f[i] = i * 1LL * f[i - 1] % MOD;
  inv[N - 1] = bigMod(f[N - 1], -1);
  for (int i = N - 1; i; --i) inv[i - 1] = i * 1LL * inv[i] % MOD;
  ll ans = 0;
  for (int k = 0; k <= n - 2; ++k) {
    ll add = f[k] * comb(n - 2, k) % MOD;
    add = add * comb(m - 1, k) % MOD;
    add = add * bigMod(m, n - 2 - k) % MOD;
    add = add * fn(k + 2) % MOD;
    ans += add; if (ans >= MOD) ans -= MOD;
  }
  cout << ans << '\n';
  return 0;
}