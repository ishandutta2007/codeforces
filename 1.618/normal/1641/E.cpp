/*
start thinking:
BULB:
result of thinking:

start coding:
AC:
*/
#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
template<class T> bool chmin(T& x, const T& y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T& x, const T& y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

#define maxn 262155
const int mod = 998244353;
int modpow(int x, int y) {
  int res = 1;
  while (y) {
    if (y & 1)
      res = (ll)res * x % mod;
    y >>= 1;
    x = (ll)x * x % mod;
  }
  return res;
}

namespace Poly {
  const int g = 3;

  int rev[maxn];
  void getRev(int logn, int n) {
    rev[0] = 0;
    for (int i = 1; i < n; i++)
      rev[i] = rev[i >> 1] >> 1 ^ (i & 1) << (logn - 1);
  }

  void ntt(vector<int> &f, int n, int sig) {
    for (int i = 0; i < n; i++)
      if (i < rev[i])
        swap(f[i], f[rev[i]]);
    for (int i = 2; i <= n; i <<= 1) {
      int wi = modpow(g, (mod - 1) / i);
      for (int j = 0; j < n; j += i) {
        int ww = 1;
        for (int k = j; k < j + i / 2; k++) {
          int lef = (f[k] + (ll)f[k + i / 2] * ww) % mod,
              rig = (f[k] - (ll)f[k + i / 2] * ww) % mod;
          f[k] = lef, f[k + i / 2] = rig;
          ww = (ll)ww * wi % mod;
        }
      }
    }
    if (sig == -1) {
      reverse(f.begin() + 1, f.end());
      int foo = modpow(n, mod - 2);
      for (int i = 0; i < n; i++)
        f[i] = (ll)f[i] * foo % mod;
    }
  }

  void mul(vector<int> &a, vector<int> b) {
    int l;
    for (l = 0; (1u << l) < a.size() + b.size() - 1; l++);
    getRev(l, 1 << l);
    l = 1 << l;
    a.resize(l);
    b.resize(l);
    ntt(a, l, 1);
    ntt(b, l, 1);
    for (int i = 0; i < l; i++)
      a[i] = (ll)a[i] * b[i] % mod;
    ntt(a, l, -1);
  }
}

int n, a[maxn], b[maxn], res[maxn];

void solve(int l, int r) {
  if (l == r)
    return;
  int mid = (l + r) >> 1;
  solve(l, mid);
  vector<int> f(mid - l + 1), g(r - mid);
  for (int i = l; i <= mid; i++)
    f[i - l] = a[i];
  for (int i = mid + 1; i <= r; i++)
    g[i - mid - 1] = b[i];
  Poly::mul(f, g);
  for (int i = 0; i < (int)f.size(); i++)
    (res[l + mid + 1 + i] += f[i]) %= mod;
  solve(mid + 1, r);
}

void hf_conv() {
  memset(res, 0, sizeof(res));

  // for (int i = 1; i <= n; i++)  
  //   cout << a[i] << " ";
  // cout << endl;
  // for (int i = 1; i <= n; i++)
  //   cout << b[i] << " ";
  // cout << endl;
  // system("pause");

  solve(1, n);

  // for (int i = 1; i <= 2 * n; i++) {
  //   cout << (res[i] + mod) % mod << " ";
  // }
  // cout << endl;
  // system("pause");

  int sum = 0;
  for (int i = n + 1; i <= 2 * n; i++) {
    (res[i] += sum) %= mod;
    (sum += a[i - n]) %= mod;
  }

  // for (int i = 1; i <= 2 * n; i++) {
  //   cout << (res[i] + mod) % mod << " ";
  // }
  // cout << endl;
  // system("pause");

}

int spe[maxn], w[maxn], ans[maxn];

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  int m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    scanf("%d", w + i);
  for (int i = 1; i <= m; i++) {
    int p;
    scanf("%d", &p);
    spe[p] = 1;
  }

  int foo = 1;
  for (int i = 1; i <= n; i++) {
    a[i] = spe[i] * foo % mod;
    if (spe[i])
      (foo <<= 1) %= mod;
  }
  foo = 1;
  for (int i = n; i >= 1; i--) {
    if (spe[i])
      (foo <<= 1) %= mod;
    b[i] = foo;
  }
  hf_conv();
  for (int i = 1; i <= n; i++)
    ans[i] = (ans[i] + (ll)i * res[i * 2]) % mod;
  for (int i = 1; i <= n; i++)
    a[i] = (ll)a[i] * i % mod;
  hf_conv();
  for (int i = 1; i <= n; i++)
    (ans[i] -= res[i * 2]) %= mod;
  
  reverse(spe + 1, spe + n + 1);
  reverse(ans + 1, ans + n + 1);
  foo = 1;
  for (int i = 1; i <= n; i++) {
    a[i] = spe[i] * foo % mod;
    if (spe[i])
      (foo <<= 1) %= mod;
  }
  foo = 1;
  for (int i = n; i >= 1; i--) {
    b[i] = foo;
    if (spe[i])
      (foo <<= 1) %= mod;
  }
  hf_conv();
  for (int i = 1; i <= n; i++)
    ans[i] = (ans[i] + (ll)i * res[i * 2]) % mod;
  for (int i = 1; i <= n; i++)
    a[i] = (ll)a[i] * i % mod;
  hf_conv();
  for (int i = 1; i <= n; i++)
    (ans[i] -= res[i * 2]) %= mod;
  
  reverse(ans + 1, ans + n + 1);
  for (int i = 1; i <= n; i++) {
    ans[0] = (ans[0] + (ll)w[i] * ans[i]) % mod;
  }
  ans[0] = (ll)ans[0] * modpow(modpow(2, m) - 1, mod - 2) % mod;
  printf("%d\n", (ans[0] + mod) % mod);
  return 0;
}