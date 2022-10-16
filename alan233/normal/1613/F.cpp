// Author: wlzhouzhuan
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
#define poly vector<int>
#define SZ(x) (int(x.size()))
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

const int mlen = 1 << 20; // maxlen
const int N = mlen + 5;
const int mod = 998244353;
ull omgs[N];
int rev[N];
int qpow(int a, int b = mod - 2) {
  int res = 1;
  while (b) {
    if (b & 1) res = 1ll * res * a % mod;
    a = 1ll * a * a % mod;
    b >>= 1; 
  }
  return res;
}
const int G = qpow(3, (mod - 1) / mlen);
void setup() {
  omgs[mlen / 2] = 1;
  for (int i = mlen / 2 + 1; i < mlen; i++) omgs[i] = G * omgs[i - 1] % mod;
  for (int i = mlen / 2 - 1; i > 0; i--) omgs[i] = omgs[i << 1];
}
int getR(int len) {
  int lim = 1, L = 0;
  while (lim <= len) lim <<= 1, L++;
  for (int i = 0; i < lim; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << L - 1); 
  return lim;
}
inline void dft(poly &a, int lim) {
  a.resize(lim);
  static ull A[N];
  for (int i = 0; i < lim; i++) A[rev[i]] = a[i];
  for (int mid = 1; mid < lim; mid <<= 1) {
    for (int i = 0; i < lim; i += mid << 1) {
      ull *W = omgs + mid;
      for (int j = 0; j < mid; j++) {
        ull tmp = *(W++) * A[i + j + mid] % mod;
        A[i + j + mid] = A[i + j] + mod - tmp;
        A[i + j] += tmp; 
      }
    }
  } 
  for (int i = 0; i < lim; i++) a[i] = A[i] % mod;
}
inline void idft(poly &a, int lim) {
  a.resize(lim);
  dft(a, lim), reverse(a.begin() + 1, a.end());
  int linv = mod - (mod - 1) / lim;
  for (int i = 0; i < lim; i++) a[i] = 1ll * a[i] * linv % mod;
}
poly operator * (poly a, poly b) {
  int len = SZ(a) + SZ(b) - 1, lim = getR(len);
  if (len <= 1024) {
    poly c(len);
    rep(i, 0, SZ(a) - 1) {
      rep(j, 0, SZ(b) - 1) {
        c[i + j] = (c[i + j] + 1ull * a[i] * b[j]) % mod;
      }
    }
    return c;
  }
  dft(a, lim), dft(b, lim);
  for (int i = 0; i < lim; i++) a[i] = 1ll * a[i] * b[i] % mod;
  idft(a, lim), a.resize(len);
  return a;
}

vector<int> adj[N]; int n;
int son[N];
void dfs1(int u, int fa) {
  for (auto v: adj[u]) {
    if (v == fa) continue;
    son[u]++;
    dfs1(v, u);
  }
}

int fac[N], ifac[N];
inline int C(int n, int m) {
  return 1ll * fac[n] * ifac[n - m] % mod * ifac[m] % mod;
}

int main() {
  setup();
  n = read();
  fac[0] = 1;
  rep(i, 1, n) fac[i] = 1ll * fac[i - 1] * i % mod;
  ifac[n] = qpow(fac[n]);
  per(i, n, 1) ifac[i - 1] = 1ll * ifac[i] * i % mod;
  rep(i, 1, n - 1) {
    int u = read(), v = read();
    adj[u].pb(v), adj[v].pb(u);
  }
  dfs1(1, 0);
  poly f = {1};
  sort(son + 1, son + n + 1, greater<int> ());
  rep(i, 1, n) {
    int j = i;
    while (j < n && son[i] == son[j + 1]) j ++;
    int up = j - i + 1;
    poly g(up + 1);
    int cf = 1;
    rep(i, 0, up) {
      int coef = 1ll * C(up, i) * cf % mod;
      g[i] = coef;
      cf = 1ll * cf * (mod - son[j]) % mod;
    }
    f = f * g;
    i = j;
  }
  int ans = 0;
  rep(i, 0, n - 1) ans = (ans + 1ll * fac[n - i] * f[i]) % mod;
  print(ans, '\n');
  return 0;
}