/*
start thinking:
BULB:
result of thinking: Pure.

i=1,2,...,np[i]p[i]=1,2,...,ni.
dp1...k.
f12, f21, f1*, f*1, f**.
f1*(l,n) = sum_{i=l+1}^n c(n-l-1,n-i)f12(l,i)f1*(i,n), 1<=l<n; f1*(n,n) = 1
c_i = f1*(n-i,n) / i!, b_i = f12(m+1,m+1+i) / (i-1)! (0 <= i < n - m)
kc_k = sum_{i=1}^k b_ic_{k-i} (1 <= k < n - m)
fftnlog^2.

f*1(1,r) = sum_{i=1}^{r-1} c(r-2,r-1-i)f*1(1,i)f21(i,r), 1<r<=n; f*1(n,n) = 1

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
template<class T> bool chmin(T &x, const T &y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T &x, const T &y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

const int LEN = 1000000;
struct fastio {
  int it, len;
  char s[LEN + 5];
  fastio() {
    it = len = 0;
  }
  char get() {
    if (it < len) return s[it++];
    it = 0, len = fread(s, 1, LEN, stdin);
    return len ? s[it++] : EOF;
  }
  bool notend() {
    char c;
    for (c = get(); c == ' ' || c == '\n' || c == '\r'; c = get());
    if (it) it--;
    return c != EOF;
  }
  void put(char c) {
    if (it == LEN) fwrite(s,1,LEN,stdout), it = 0;
    s[it++] = c;
  }
  void flush() {
    fwrite(s, 1, it, stdout);
  }
}buff, bufo;
inline int getint() {
  char c; int res = 0, sig = 1;
  for (c = buff.get(); c < '0' || c > '9'; c = buff.get()) if(c == '-') sig = -1;
  for (; c >= '0' && c <= '9'; c = buff.get()) res = res * 10 + (c - '0');
  return sig * res;
}
inline ll getll() {
  char c; ll res = 0, sig = 1;
  for (c = buff.get(); c < '0' || c > '9'; c = buff.get()) if (c == '-') sig = -1;
  for (; c >= '0' && c <= '9'; c = buff.get()) res = res * 10 + (c - '0');
  return sig * res;
}
inline char getVisibleChar() {
  char c;
  for (c = buff.get(); c == ' ' || c == '\n' || c == '\r'; c = buff.get());
  return c;
}
inline void putint(int x) {
  if (!x) bufo.put('0');
  else {
    if (x < 0) bufo.put('-'), x = -x;
    int k = 0; char s[15];
    while (x) {
      s[++k] = x % 10 + '0';
      x /= 10;
    }
    for (; k; k--) bufo.put(s[k]);
  }
}
inline void putll(ll x) {
  if (!x) bufo.put('0');
  else {
    if (x < 0) bufo.put('-'), x = -x;
    int k = 0; char s[25];
    while (x) {
      s[++k] = x % 10 + '0';
      x /= 10;
    }
    for (; k; k--) bufo.put(s[k]);
  }
}

#define maxn 200005
#define maxm 105
const int mod = 998244353;
void chadd(int &x, int b) {
  x += b;
  if (x >= mod)
    x -= mod;
  else if (x <= -mod)
    x += mod;
}
int modadd(int x, int y) {
  x += y;
  if (x >= mod)
    x -= mod;
  else if (x <= -mod)
    x += mod;
  return x;
}
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

int n, m, a12[maxm][maxn], a21[maxm][maxn], pow2[maxn], fct[maxn], invfct[maxn];
char s[maxm];

int binom(int x, int y) {
  return (ll)fct[x] * invfct[y] % mod * invfct[x - y] % mod;
}

void get12() {
  if (m + 2 <= n)
    a12[m + 1][m + 2] = a21[m + 1][m + 2] = 1;
  for (int i = m + 3; i <= n; i++) {
    a12[m + 1][i] = a21[m + 1][i] = pow2[i - m - 3];
  }
  for (int i = m; i >= 1; i--) {
    (s[i] == '<' ? a12[i][i + 1] : a21[i][i + 1]) = 1;
    if (i + 2 <= n) {
      a12[i][i + 2] = a21[i][i + 2]
        = (s[i] == '<' && (i + 1 > m || s[i + 1] == '>'));
    }
    for (int j = i + 3; j <= n; j++) {
      if (s[i] == '<') {
        chadd(a12[i][j], a21[i + 1][j]);
        chadd(a21[i][j], a21[i + 1][j]);
      }
      if (j > m + 1 || s[j - 1] == '>') {
        chadd(a12[i][j], a12[i][j - 1]);
        chadd(a21[i][j], a12[i][j - 1]);
      }
    }
  }
}

namespace Poly {
  #define LEN 524295
  const int g = 3;
  const int invg = 332748118;

  int rev[LEN], w[LEN], invw[LEN];
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

  #undef LEN
}

int b[maxn], c[maxn], f1x[maxn], fx1[maxn];

void solve1x(int l, int r) {
  if (l == r) {
    if (l)
      c[l] = (ll)c[l] * modpow(l, mod - 2) % mod;
    return;
  }
  int mid = (l + r) >> 1;
  solve1x(l, mid);
  vector<int> f(mid - l + 1), g(r - l);
  for (int i = l; i <= mid; i++)
    f[i - l] = c[i];
  for (int i = 0; i < r - l; i++) 
    g[i] = b[i + 1];
  f = Poly::mul(f, g);
  for (int i = mid + 1; i <= r; i++)
    chadd(c[i], f[i - l - 1]);
  solve1x(mid + 1, r);
}

void solvex1(int l, int r) {
  if (l == r) {
    c[l] = (ll)c[l] * modpow(l, mod - 2) % mod;
    return;
  }
  int mid = (l + r) >> 1;
  solvex1(l, mid);
  vector<int> f(mid - l + 1), g(r - l);
  for (int i = l; i <= mid; i++)
    f[i - l] = c[i];
  for (int i = 0; i < r - l; i++)
    g[i] = b[i + 1];
  f = Poly::mul(f, g);
  for (int i = mid + 1; i <= r; i++)
    chadd(c[i], f[i - l - 1]);
  solvex1(mid + 1, r);
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  n = getint(), m = getint();
  pow2[0] = fct[0] = 1;
  for (int i = 1; i <= n; i++) {
    fct[i] = (ll)fct[i - 1] * i % mod;
    pow2[i] = modadd(pow2[i - 1], pow2[i - 1]);
  }
  invfct[n] = modpow(fct[n], mod - 2);
  for (int i = n; i >= 1; i--)
    invfct[i - 1] = (ll)invfct[i] * i % mod;
  for (int i = 1; i <= m; i++)
    s[i] = getVisibleChar();
  get12();
  for (int i = 1; i < n - m; i++)
    b[i] = (ll)a12[m + 1][m + 1 + i] * invfct[i - 1] % mod;
  c[0] = 1;
  solve1x(0, n - m - 1);
  for (int i = 0; i < n - m; i++)
    f1x[n - i] = (ll)c[i] * fct[i] % mod;
  for (int i = m; i >= 1; i--) {
    for (int j = i + 1; j <= n; j++) {
      chadd(f1x[i], (ll)binom(n - i - 1, n - j) * a12[i][j] % mod * f1x[j] % mod);
    }
  }
  memset(c, 0, sizeof(c));
  c[0] = 1;
  for (int i = 1; i < m; i++) {
    for (int j = 0; j < i; j++) {
      chadd(c[i], (ll)c[j] * a21[j + 1][i + 1] % mod * invfct[i - j - 1] % mod);
    }
    c[i] = (ll)c[i] * modpow(i, mod - 2) % mod;
  }
  for (int i = m; i <= n; i++) {
    for (int j = 0; j < m; j++) {
      chadd(c[i], (ll)c[j] * a21[j + 1][i + 1] % mod * invfct[i - j - 1] % mod);
    }
  }
  for (int i = 1; i < n - m; i++)
    b[i] = (ll)a21[m + 1][m + 1 + i] * invfct[i - 1] % mod;
  solvex1(m, n - 1);
  for (int i = 0; i < n; i++)
    fx1[1 + i] = (ll)c[i] * fct[i] % mod;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    chadd(ans, (ll)binom(n - 1, i - 1) * fx1[i] % mod * f1x[i] % mod);
  }
  printf("%d\n", (ans + mod) % mod);
  return 0;
}