// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
#pragma GCC target("avx", "avx2")
#ifdef xay
#define D(...) fprintf(stderr, "[D]" __VA_ARGS__)
#else
#define D(...) ((void)0)
#endif
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

const int N = 200005; /* ! */
const int mod = 998244353;

inline int qpow(int a, int b = mod - 2) {
  int res = 1;
  while (b) {
    if (b & 1) res = 1ll * res * a % mod;
    a = 1ll * a * a % mod;
    b >>= 1;
  }
  return res;
}
int fac[N], ifac[N], inv[N];
inline void init(int n) {
  fac[0] = ifac[0] = 1;
  inv[1] = 1;
  rep(i, 2, n) inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
  rep(i, 1, n) fac[i] = 1ll * fac[i - 1] * i % mod;
  ifac[n] = qpow(fac[n]);
  per(i, n, 1) ifac[i - 1] = 1ll * ifac[i] * i % mod;
}
inline int C(int n, int m) {
  return 1ll * fac[n] * ifac[n - m] % mod * ifac[m] % mod;
}

int a[N], n;

void solve() {
  n = read();
  int mx = 0, cnt1 = 0, cnt2 = 0;
  rep(i, 1, n) a[i] = read(), mx = max(mx, a[i]);
  rep(i, 1, n) {
    if (a[i] == mx) cnt1++;
    if (a[i] == mx - 1) cnt2++;
  }
  if (cnt1 >= 2) {
    print(fac[n], '\n');
  } else {
    print(1ll * fac[n] * inv[cnt2 + 1] % mod * cnt2 % mod, '\n');
  }
}

int main() {
  init(200000);
  int T = read();
  while (T--) solve();
  return 0;
}