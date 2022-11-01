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

int f_a[N], f_b[N];

vector <int> multiply (vector <int> a, vector <int> b) {
  int sz = 1, n = a.size(), m = b.size();
  while (sz < n + m - 1) sz <<= 1; prepare(sz);
  for (int i = 0; i < sz; ++i) f_a[i] = i < n ? a[i] : 0;
  for (int i = 0; i < sz; ++i) f_b[i] = i < m ? b[i] : 0;
  ntt(f_a, sz, 0); ntt(f_b, sz, 0);
  for (int i = 0; i < sz; ++i) f_a[i] = (ll) f_a[i] * f_b[i] % MOD;
  ntt(f_a, sz, 1); return vector <int> (f_a, f_a + n + m - 1);
}

const int K = 7;

map <int, int> freq;
vector <int> one, two;
int n, k, q, a[N], b[N], f[N], inv[N], ans[K][N];

int main() {
  f[0] = 1;
  for (int i = 1; i < N; ++i) f[i] = (ll) i * f[i - 1] % MOD;
  inv[N - 1] = bigMod(f[N - 1], -1, MOD);
  for (int i = N - 1; i; --i) inv[i - 1] = (ll) i * inv[i] % MOD;
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) scanf("%d", a + i), ++freq[a[i]];
  for (int i = 1; i <= k; ++i) scanf("%d", b + i);
  for (auto it : freq) {
    if (it.second == 1) one.emplace_back(it.first);
    else two.emplace_back(it.first);
  }
  for (int i = 1; i <= k; ++i) {
    int x = lower_bound(one.begin(), one.end(), b[i]) - one.begin();
    int y = lower_bound(two.begin(), two.end(), b[i]) - two.begin();
    int p = x + 2 * y;
    vector <int> s(p + 1), t(p + 1);
    for (int j = 0; j <= p; ++j) {
      if (j > x) s[j] = 0;
      else {
        s[j] = (ll) f[p - j] * inv[j] % MOD;
        s[j] = (ll) s[j] * inv[x - j] % MOD;  
      }
      t[j] = inv[j];
    }
    vector <int> prod = multiply(s, t);
    for (int j = 0; j <= p; ++j) {
      ans[i][j] = (ll) f[x] * prod[j] % MOD;
      ans[i][j] = (ll) ans[i][j] * inv[p - j] % MOD;
    }
  }
  cin >> q;
  while (q--) {
    int x, ret = 0;
    scanf("%d", &x);
    x >>= 1; --x;
    for (int i = 1; i <= k; ++i) {
      if (x >= b[i]) {
        ret += ans[i][x - b[i]];
        if (ret >= MOD) ret -= MOD;
      }
    }
    printf("%d\n", ret);
  }
  return 0;
}