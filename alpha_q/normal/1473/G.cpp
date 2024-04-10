#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int G = 3;
const int N = 400010;
const int MOD = 998244353;

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

void prepare (int n) { 
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

int f_a[N], f_b[N];

vector <ll> multiply (vector <ll> a, vector <ll> b) {
  int sz = 1, n = a.size(), m = b.size();
  while (sz < n + m - 1) sz <<= 1; prepare(sz);
  for (int i = 0; i < sz; ++i) f_a[i] = i < n ? a[i] : 0;
  for (int i = 0; i < sz; ++i) f_b[i] = i < m ? b[i] : 0;
  ntt(f_a, sz, 0); ntt(f_b, sz, 0);
  for (int i = 0; i < sz; ++i) f_a[i] = (ll) f_a[i] * f_b[i] % MOD;
  ntt(f_a, sz, 1); return vector <ll> (f_a, f_a + n + m - 1);
}

int n;
ll a[N], b[N], fac[N], inv[N];

inline ll comb (ll x, ll y) {
  if (x < y or y < 0) return 0;
  return fac[x] * (inv[y] * inv[x - y] % MOD) % MOD;
}

int main() {
  fac[0] = 1;
  for (int i = 1; i < N; ++i) fac[i] = i * fac[i - 1] % MOD;
  inv[N - 1] = bigMod(fac[N - 1], -1, MOD);
  for (int i = N - 1; i; --i) inv[i - 1] = i * inv[i] % MOD;
  cin >> n;
  vector <ll> poly({1});
  for (int i = 1; i <= n; ++i) {
    cin >> a[i] >> b[i];
    int up = poly.size() - 1;
    vector <ll> now;
    if (b[i] < up) {
      now.resize(up + a[i] + 1);
      for (int j = 0; j < now.size(); ++j) {
        now[j] = comb(a[i] + b[i], j);
      }
      vector <ll> prod = multiply(poly, now);
      for (int j = b[i]; j <= up + a[i]; ++j) {
        prod[j - b[i]] = prod[j];
      }
      prod.resize(up + a[i] - b[i] + 1);
      poly = prod; continue;
    }
    int diff = b[i] - up;
    now.resize(up + a[i] - diff + 1);
    for (int j = 0; j < now.size(); ++j) {
      now[j] = comb(a[i] + b[i], diff + j);
    }
    vector <ll> prod = multiply(poly, now);
    for (int j = b[i] - diff; j <= up + a[i] - diff; ++j) {
      prod[j - b[i] + diff] = prod[j];
    }
    prod.resize(up + a[i] - b[i] + 1);
    poly = prod; continue;
  }
  ll ans = 0;
  for (ll &x : poly) ans += x, ans %= MOD;
  cout << ans << '\n';
  return 0;
}