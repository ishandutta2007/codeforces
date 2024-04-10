/*
start thinking:
BULB:
result of thinking: Pure.

k = 1  n  more-equal array .
 n = 1, 2, 3, 4  1, 3, 16, 125 .
 n  more-equal array  (n + 1) ^ (n - 1).
,  n  n + 1  1, 2, ..., n + 1 
,  (n + 1) ^ n ,  >= 2  i  i + 1 
, , iff  #(n + 1) ,
 (n + 1) ^ n ,  \sum_{i = 1}^{n + 1} cnt[i] ^ k 
 n + 1 .
 = \sum_{a \in F_{n + 1}^n} cnt(a, 1)^k
     = \sum_{i = 0}^n C(n, i) n^(n - i) i^k
     = \sum_{i = 0}^n C(n, i) n^(n - i) \sum_{j = 0}^k S2(k, j) i^\underline{j}
     = \sum_{j = 0}^k S2(k, j) n^\underline{j} 2^(n - j) ( )
 S2:
(-1)^i S2(n, i) = \sum_{j = 0}^i (-1)^j j^n / j! \cdot 1 / (i - j)!

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
template<class T1, class T2> bool chmin(T1 &x, const T2 &y) {
  return x > y ? (x = y, true) : false;
}
template<class T1, class T2> bool chmax(T1 &x, const T2 &y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

const int mod = 998244353;
const int inv2 = 499122177;
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
  #define maxn 262155
  const int g = 3;
  const int invg = 332748118;
  void chadd(int &x, int b) {
    x += b;
    if (x >= mod)
      x -= mod;
    else if (x <= -mod)
      x += mod;
  }
 
  int rev[maxn], w[maxn], invw[maxn];
  void ini(int logn, int n) {
    rev[0] = 0;
    for (int i = 1; i < n; i++) 
      rev[i] = rev[i >> 1] >> 1 ^ (i & 1) << (logn - 1);
    w[0] = invw[0] = 1;
    w[1] = modpow(g, (mod - 1) / n);
    invw[1] = modpow(invg, (mod - 1) / n);
    for (int i = 2; i <= n; i++)
      w[i] = (ll)w[i - 1] * w[1] % mod, invw[i] = (ll)invw[i - 1] * invw[1] % mod;
  }
 
  void ntt(vector<int> &f, int n, int sig) {
    for (int i = 0; i < n; i++)
      if (i < rev[i])
        swap(f[i], f[rev[i]]);
    for (int i = 2; i <= n; i <<= 1) {
      for (int j = 0; j < n; j += i) {
        int *wcur = ~sig ? w : invw, stp = n / i;
        for (int k = j; k < j + i / 2; k++) {
          ll bar = (ll)f[k + i / 2] * *wcur;
          f[k + i / 2] = (f[k] - bar) % mod, f[k] = (f[k] + bar) % mod;
          wcur += stp;
        }
      }
    }
    if (sig == -1) {
      int foo = modpow(n, mod - 2);
      for (int i = 0; i < n; i++)
        f[i] = (ll)f[i] * foo % mod;
    }
  }
 
  vector<int> add(vector<int> a, vector<int> b) {
    int n = max(a.size(), b.size());
    a.resize(n);
    b.resize(n);
    for (int i = 0; i < n; i++)
      chadd(a[i], b[i]);
    return a;
  }
 
  vector<int> sub(vector<int> a, vector<int> b) {
    int n = max(a.size(), b.size());
    a.resize(n);
    b.resize(n);
    for (int i = 0; i < n; i++)
      chadd(a[i], -b[i]);
    return a;
  }
 
  vector<int> mul(vector<int> a, vector<int> b) {
    int n = a.size(), m = b.size(), l = 1;
    while (l < n + m - 1)
      l <<= 1;
    a.resize(l);
    b.resize(l);
    vector<int> c(l);
    ini(__builtin_ctz(l), l);
    ntt(a, l, 1);
    ntt(b, l, 1);
    for (int i = 0; i < l; i++)
      c[i] = (ll)a[i] * b[i] % mod;
    ntt(c, l, -1);
    c.resize(n + m - 1);
    return c;
  }
 
  // [x^0]a != 0
  vector<int> inv(vector<int> a) {
    int n = a.size();
    vector<int> b(1);
    b[0] = modpow(a[0], mod - 2);
    for (int i = 1; i < n; i <<= 1) {
      b.resize(i << 2);
      vector<int> foo(i << 2);
      for (int j = 0; j < (i << 1); j++) {
        if (j < (int)a.size())
          foo[j] = a[j];
      }
      ini(__builtin_ctz(i) + 2, i << 2);
      ntt(foo, i << 2, 1);
      ntt(b, i << 2, 1);
      for (int j = 0; j < (i << 2); j++)
        b[j] = (2 * b[j] - (ll)b[j] * b[j] % mod * foo[j]) % mod;
      ntt(b, i << 2, -1);
      b.resize(i << 1);
    }
    b.resize(n);
    return b;
  }
 
  // a=1
  vector<int> sqrt(vector<int> a) {
    int n = a.size();
    vector<int> b(1, 1);
    for (int i = 1; i < n; i <<= 1) {
      b.resize(i << 1);
      vector<int> foo(i << 2);
      for (int j = 0; j < (i << 1); j++) {
        if (j < (int)a.size())
          foo[j] = a[j];
      }
      auto invb = inv(b);
      invb.resize(i << 2);
      ini(__builtin_ctz(i) + 2, i << 2);
      ntt(foo, i << 2, 1);
      ntt(invb, i << 2, 1);
      for (int j = 0; j < (i << 2); j++)
        invb[j] = (ll)foo[j] * invb[j] % mod;
      ntt(invb, i << 2, -1);
      for (int j = 0; j < (i << 1); j++)
        b[j] = ll(b[j] + invb[j]) * inv2 % mod;
    }
    b.resize(n);
    return b;
  }
 
  // a / b
  vector<int> div(vector<int> a, vector<int> b) {
    int n = a.size(), m = b.size();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    a.resize(n - m + 1);
    b.resize(n - m + 1);
    auto c = mul(a, inv(b));
    c.resize(n - m + 1);
    reverse(c.begin(), c.end());
    return c;
  }
 
  // a=1
  vector<int> ln(vector<int> a) {
    int n = a.size();
    vector<int> d(n);
    for (int i = 0; i + 1 < n; i++)
      d[i] = ll(i + 1) * a[i + 1] % mod;
    a = mul(d, inv(a));
    for (int i = n - 1; i >= 1; i--)
      a[i] = (ll)a[i - 1] * modpow(i, mod - 2) % mod;
    a[0] = 0;
    a.resize(n);
    return a;
  }
 
  // a=0
  vector<int> exp(vector<int> a) {
    int n = a.size();
    vector<int> b(1, 1);
    for (int i = 1; i < n; i <<= 1) {
      b.resize(i << 1);
      vector<int> foo(i << 1);
      for (int j = 0; j < (i << 1); j++) {
        if (j < (int)a.size())
          foo[j] = a[j];
      }
      b = sub(b, mul(b, sub(ln(b), foo)));
    }
    b.resize(n);
    return b;
  }
 
  // [x^0]a = 1.
  vector<int> fpow(vector<int> a, int k) {
    int n = a.size();
    a = ln(a);
    for (int i = 0; i < n; i++)
      a[i] = (ll)a[i] * k % mod;
    return exp(a);
  }

  #undef maxn
}

#define maxk 100005
int n, k, fct[maxk], invfct[maxk];

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  scanf("%d%d", &n, &k);
  fct[0] = 1;
  for (int i = 1; i <= k; i++)
    fct[i] = (ll)fct[i - 1] * i % mod;
  invfct[k] = modpow(fct[k], mod - 2);
  for (int i = k; i >= 1; i--)
    invfct[i - 1] = (ll)invfct[i] * i % mod;
  vector<int> f(k + 1), g(k + 1);
  for (int i = 0; i <= k; i++) {
    f[i] = (ll)modpow(i, k) * invfct[i] % mod;
    if (i & 1)
      f[i] *= -1;
    g[i] = invfct[i];
  }
  f = Poly::mul(f, g);
  f.resize(k + 1);
  for (int i = 1; i <= k; i += 2)
    f[i] *= -1;
  int foo = 1, ans = 0;
  for (int i = 0; i <= min(n, k); i++) {
    ans = (ans + (ll)f[i] * foo % mod * modpow(n + 1, n - i))
            % mod;
    foo = (ll)foo * (n - i) % mod;
  }
  printf("%d\n", (ans + mod) % mod);
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}