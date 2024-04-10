#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int G = 3;
const int MOD = 998244353;
const int N = (1 << 20) + 5;

int rev[N], w[N], inv_n;

int bigMod (int a, int e, int mod) {
  if (e == -1) e = mod - 2;
  int ret = 1;
  while (e) {
    if (e & 1) ret = (ll) ret * a % mod;
    a = (ll) a * a % mod; e >>= 1;
  }
  return ret;
}

void prepare (int &n) { 
  int sz = abs(31 - __builtin_clz(n));
  int r = bigMod(G, (MOD - 1) / n, MOD); 
  inv_n = bigMod(n, MOD - 2, MOD), w[0] = w[n] = 1; 
  for (int i = 1; i < n; ++i) w[i] = (ll) w[i - 1] * r % MOD;
  for (int i = 1; i < n; ++i) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (sz - 1));
}

void ntt (int *a, int n, int dir) { 
  for (int i = 1; i < n - 1; ++i) { 
    if (i < rev[i]) swap(a[i], a[rev[i]]);
  }
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

int n, k, h[N], e, ans = 1, mul, f[N];

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    scanf("%d", h + i);
  }
  for (int i = 0; i < n; ++i) {
    if (h[i] ^ h[(i + 1) % n]) ++e;
    else ans = (ll) ans * k % MOD;
  }
  f[0] = 1, f[1] = k - 2, f[2] = 1;
  int sz = 1; while (sz <= e + e) sz <<= 1; prepare(sz);
  ntt(f, sz, 0);
  for (int i = 0; i < sz; ++i) f[i] = bigMod(f[i], e, MOD);
  ntt(f, sz, 1);
  for (int i = e + 1; i < sz; ++i) mul = (mul + f[i]) % MOD;
  ans = (ll) ans * mul % MOD;
  cout << ans << '\n';
  return 0;
}