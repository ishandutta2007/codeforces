#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 200010;
const ll INF = 1e10 + 5;
const int MOD = 1e9 + 7;
const int INV = 1 + MOD >> 1;

ll bigMod (ll a, ll e) {
  if (e < 0) e += MOD - 1;
  ll ret = 1;
  while (e) {
    if (e & 1) ret = ret * a % MOD;
    a = a * a % MOD, e >>= 1;
  }
  return ret;
}

int n; ll t, fac[N], inv[N], p[N];

inline void add (ll &x, ll y) {
  x += y; if (x >= MOD) x -= MOD;
}

inline ll comb (ll x, ll y) {
  if (y < 0 or x < y) return 0;
  return fac[x] * (inv[y] * inv[x - y] % MOD) % MOD;
}

int main() {
  fac[0] = 1;
  for (int i = 1; i < N; ++i) fac[i] = i * fac[i - 1] % MOD;
  inv[N - 1] = bigMod(fac[N - 1], -1);
  for (int i = N - 1; i; --i) inv[i - 1] = i * inv[i] % MOD;
  cin >> n >> t;
  ll ans = 0;
  for (int i = 1; i <= n; ++i) scanf("%lld", p + i);
  p[n + 1] = INF;
  // ll its = 0;
  for (int i = 1; i <= n; ++i) {
    ll cur = p[i + 1], here = 0;
    p[i] += p[i - 1];
    ll lt = max(0LL, t - p[i] - cur + 1), rt = min((ll) i, t - p[i]);
    // cout << lt << " " << rt << endl;
    // its += max(0LL, rt - lt + 1);
    for (ll j = lt; j <= rt; ++j) add(here, comb(i, j));
    ll at = t - p[i] - cur;
    if (at >= 0 and at <= i) add(here, INV * comb(i, at) % MOD);
    here = here * (i * bigMod(2, -i) % MOD) % MOD;
    add(ans, here);
  }
  // cout << its << endl;
  cout << ans << endl;
  return 0;
}


// p1, p2, ..., pn
// sum i / 2^i * [iC0 + iC1 + ... + iC(t - pi)]