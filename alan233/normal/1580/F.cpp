// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

#define poly vector<int>
#define SZ(a) int(a.size())
 
const int mod = 998244353;
const int G = 3, Gi = 332748118;
int add(int x, int y) {
  if ((x += y) >= mod) x -= mod;
  return x;
}
int sub(int x, int y) {
  if ((x -= y) < 0) x += mod;
  return x; 
}
int qpow(int a, int b = mod - 2) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = 1ll * res * a % mod;
    a = 1ll * a * a % mod;
    b >>= 1;
  }
  return res;
}
namespace Poly {
vector<int> Rev, W;
int lim, L;
void getR(int len) {
  lim = 1, L = 0;
  while (lim <= len) lim <<= 1, L++;
  Rev.resize(lim), W.resize(lim), W[0] = 1;
  for (int i = 0; i < lim; i++) Rev[i] = (Rev[i >> 1] >> 1) | ((i & 1) << L - 1);
}
void wf(poly &a) {
  int n = a.size();
  for (int i = 0; i < n; i++) a[i] = 1ll * (i + 1) * a[i + 1] % mod;
  a[n - 1] = 0;
}
void jf(poly &a) {
  int n = a.size();
  for (int i = n - 1; i >= 1; i--) a[i] = 1ll * a[i - 1] * qpow(i) % mod;
  a[0] = 0;
}
void NTT(poly &a, int opt) {
  for (int i = 0; i < lim; i++) if (i < Rev[i]) swap(a[i], a[Rev[i]]);
  for (int mid = 1; mid < lim; mid <<= 1) {
    int Wn = qpow(opt == 1 ? G : Gi, (mod - 1) / (mid << 1));
    for (int k = 1; k < mid; k++) W[k] = 1ll * W[k - 1] * Wn % mod;
    for (int j = 0; j < lim; j += mid << 1) {
      for (int k = 0; k < mid; k++) {
        int x = a[j + k], y = 1ll * W[k] * a[j + k + mid] % mod;
        a[j + k] = add(x, y);
        a[j + k + mid] = sub(x, y);
      }
    }
  }
  if (opt == -1) {
    int linv = qpow(lim);
    for (int i = 0; i < lim; i++) a[i] = 1ll * a[i] * linv % mod;
  }
}
poly operator * (poly a, poly b) {
  int len = a.size() + b.size() - 1;
  getR(len);
  a.resize(lim), b.resize(lim);
  NTT(a, 1), NTT(b, 1);
  for (int i = 0; i < lim; i++) a[i] = 1ll * a[i] * b[i] % mod;
  NTT(a, -1);
  a.resize(len);
  return a;
}
poly Inv(poly a) {
  if (SZ(a) == 1) return vector<int> (1, qpow(a[0]));
  int len = a.size();
  poly ta = a; ta.resize((len + 1) / 2);
  poly tb = Inv(ta);
  getR(2 * len), a.resize(lim), tb.resize(lim);
  NTT(a, 1), NTT(tb, 1);
  for (int i = 0; i < lim; i++) tb[i] = 1ll * tb[i] * (mod + 2 - 1ll * a[i] * tb[i] % mod) % mod;
  NTT(tb, -1);
  tb.resize(len);
  return tb;
}
poly Ln(poly a) {
  poly ta = a; wf(ta);
  int len = a.size();
  a = ta * Inv(a), jf(a);
  a.resize(len);
  return a;
}
poly Exp(poly a) {
  if (SZ(a) == 1) return vector<int> (1, 1);
  int len = a.size();
  poly ta = a; ta.resize((len + 1) / 2);
  poly tb = Exp(ta); tb.resize(len);
  poly Lnb = Ln(tb);
  assert(Lnb.size() == len);
  for (int i = 0; i < len; i++) Lnb[i] = (a[i] - Lnb[i] + mod) % mod;
  Lnb[0] = (Lnb[0] + 1) % mod;
  tb = tb * Lnb;
  tb.resize(len);
  return tb;
}
}
using namespace Poly;

const int N = 300005; /* ! */

int fac[N], ifac[N], inv[N];
inline void init(int n) {
  inv[1] = 1;
  rep(i, 2, n) inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
  fac[0] = ifac[0] = 1;
  rep(i, 1, n) fac[i] = 1ll * fac[i - 1] * i % mod;
  ifac[n] = qpow(fac[n]);
  per(i, n, 1) ifac[i - 1] = 1ll * ifac[i] * i % mod;
}
inline int C(int n, int m) {
  return 1ll * fac[n] * ifac[n - m] % mod * ifac[m] % mod;
}

int n, m;

void rev(poly &a) {
  a[0] = 1;
  rep(i, 1, SZ(a) - 1) a[i] = (mod - a[i]) % mod;
}

int main() {
  init(N - 5);
  cin >> n >> m;
  vector<int> a(n + 1), b(n + 1);
  int cur = 1;
  rep(i, 1, n) {
    int t = (m + i) / 2;
    if ((m + i) & 1) cur = 1ll * cur * (t - i + 1) % mod;
    else cur = 1ll * cur * t % mod;
    cur = 1ll * cur * inv[i] % mod;
    if (i & 1) b[i] = ((i / 2) & 1 ? -1 : 1) * cur;
    else a[i] = ((i / 2) & 1 ? 1 : -1) * cur;
    a[i] = (a[i] + mod) % mod;
    b[i] = (b[i] + mod) % mod;
  }
  rev(a);
  poly c = b * Inv(a);
  rev(c);
  poly f = Ln(Inv(a));
  poly g = Ln(Inv(c));
  print(1ll * n * (f[n] + g[n]) % mod, '\n');
  return 0;
}