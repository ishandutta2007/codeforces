#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int G = 3;
const int N = 1 << 21;
const int MOD = 998244353;

int rev[N], w[N], inv_n;

int bigMod (int a, int e) {
  int ret = 1;
  while (e) {
    if (e & 1) ret = (ll) ret * a % MOD;
    a = (ll) a * a % MOD, e >>= 1;
  }
  return ret;
}

void prepare (int n) { 
  int sz = 31 - __builtin_clz(n); sz = abs(sz);
  int r = bigMod(G, (MOD - 1) / n); 
  inv_n = bigMod(n, MOD - 2);
  w[0] = w[n] = 1; 
  for (int i = 1; i < n; ++i) w[i] = (ll) w[i - 1] * r % MOD;
  for (int i = 1; i < n; ++i) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (sz - 1));
}

void ntt (int *a, int n, int dir) { 
  for (int i = 1; i < n - 1; ++i) 
    if (i < rev[i]) swap(a[i], a[rev[i]]);
  for (int m = 2; m <= n; m <<= 1) {
    for (int i = 0; i < n; i += m) {
      for (int j = 0; j < (m >> 1); ++j) {
        int &u = a[i + j], &v = a[i + j + (m >> 1)]; 
        int t = (ll) v * w[dir ? n - n / m * j : n / m * j] % MOD;
        v = u - t < 0 ? u - t + MOD : u - t;
        u = u + t >= MOD ? u + t - MOD : u + t;
      }
    }
  } if (dir) for (int i = 0; i < n; ++i) a[i] = (ll) a[i] * inv_n % MOD;
}

int n, k, x, a[N];

int main() {
  cin >> n >> k;
  while (k--) cin >> x, a[x] = 1;
  prepare(N >> 1);
  ntt(a, N >> 1, 0);
  for (int i = 0; i < N >> 1; ++i) {
    a[i] = bigMod(a[i], n >> 1);
  }
  ntt(a, N >> 1, 1);
  ll ans = 0;
  for (int i = 0; i < N >> 1; ++i) {
    ans += (ll) a[i] * a[i];
    ans %= MOD;
  }
  cout << ans << '\n';
  return 0;
}