// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
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

const int N = 100005; /* ! */
const int mod = 1e9 + 7;

inline int qpow(int a, int b = mod - 2) {
  int res = 1;
  while (b) {
    if (b & 1) res = 1ll * res * a % mod;
    a = 1ll * a * a % mod;
    b >>= 1;
  }
  return res;
}
int fac[N], ifac[N];
inline void init(int n) {
  fac[0] = ifac[0] = 1;
  rep(i, 1, n) fac[i] = 1ll * fac[i - 1] * i % mod;
  ifac[n] = qpow(fac[n]);
  per(i, n, 1) ifac[i - 1] = 1ll * ifac[i] * i % mod;
}
inline int C(int n, int m) {
  return 1ll * fac[n] * ifac[n - m] % mod * ifac[m] % mod;
}

map<int, int> cnt;
int f[N], zyk;
int a[N], buc[N], pw[N], n, k;

inline int gao(int x) {
  int res = 0;
  rep(i, 0, zyk) {
    int coef = 1ll * f[x + i] * C(zyk, i) % mod * pw[zyk - i] % mod;
    res = (res + coef) % mod;
  }
  return res;
}

int main() {
  init(N - 5);
  n = read(), k = read();
  pw[0] = 1;
  rep(i, 1, n) {
    pw[i] = 1ll * pw[i - 1] * (k - 1) % mod;
    a[i] = read();
    if (a[i] == -1) zyk++;
    else cnt[a[i]]++;
  }
  f[0] = 0, f[1] = 0;
  rep(a, 1, n - 1) {
    f[a + 1] = 1ll * (1ll * (k - 1) * a % mod * f[a - 1] + 1ll * (2ll * a - 1ll * a * k % mod - n) * f[a] + 1ll * a * k) % mod * qpow(a - n) % mod;
    if (f[a + 1] < 0) f[a + 1] += mod;
  }
//  rep(i, 1, n) printf("f[%d] = %d\n", i, f[i]);
  int qwq = 0;
  rep(i, 1, n) {
    if (a[i] != -1 && cnt[a[i]]) {
      buc[cnt[a[i]]]++;
      cnt[a[i]] = 0;
      qwq++;
    }
  }
  buc[0] += k - qwq;
  int ans = 0;
  rep(i, 0, n) {
    if (buc[i]) {
      ans = (ans + 1ll * buc[i] * gao(i)) % mod;
    }
  }
  ans = 1ll * ans * qpow(qpow(k, zyk)) % mod;
  print((ans + mod - f[n]) % mod, '\n');
  return 0;
}