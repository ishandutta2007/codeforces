// Author: wlzhouzhuan
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

#define poly vector<int>

const int mod = 998244353;
const int G = 3, Gi = 332748118;
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
  vector<int> Rev;
  int lim, L;
  void getR(int len) {
    lim = 1, L = 0;
    while (lim <= len) lim <<= 1, L++;
    Rev.resize(lim);
    for (int i = 0; i < lim; i++) Rev[i] = (Rev[i >> 1] >> 1) | ((i & 1) << L - 1);
  }
  void NTT(poly &a, int opt) {
    for (int i = 0; i < lim; i++) if (i < Rev[i]) swap(a[i], a[Rev[i]]);
    for (int mid = 1; mid < lim; mid <<= 1) {
      int Wn = qpow(opt == 1 ? G : Gi, (mod - 1) / (mid << 1));
      for (int j = 0; j < lim; j += mid << 1) {
        for (int k = 0, W = 1; k < mid; k++, W = 1ll * W * Wn % mod) {
          int x = a[j + k], y = 1ll * W * a[j + k + mid] % mod;
          a[j + k] = (x + y) % mod;
          a[j + k + mid] = (x - y + mod) % mod;
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
}
using namespace Poly;

int n, k;

int fac[100005], ifac[100005];
void init(int n) {
  fac[0] = ifac[0] = 1;
  rep(i, 1, n) fac[i] = 1ll * fac[i - 1] * i % mod;
  ifac[n] = qpow(fac[n]);
  per(i, n, 1) ifac[i - 1] = 1ll * ifac[i] * i % mod; 
}

int main() {
  init(1e5);
  cin >> n >> k;
  poly f(k + 1), g(k + 1);
  for (int i = 0; i <= k; i++) {
    if (i & 1) f[i] = (mod - ifac[i]) % mod;
    else f[i] = ifac[i];
    g[i] = 1ll * qpow(i, k) * ifac[i] % mod;
  }  
  f = f * g;
  int ans = 0, coef = 1;
  for (int i = 0; i <= k; i++) {
    ans = (ans + 1ll * coef * f[i] % mod * qpow(n + 1, n - i)) % mod;
    coef = 1ll * coef * (n - i) % mod;
  }
  print(ans, '\n');
}