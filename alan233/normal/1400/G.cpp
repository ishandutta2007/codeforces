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

const int N = 300005;
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
int fac[N], ifac[N];
inline void init(int n) {
  fac[0] = ifac[0] = 1;
  rep(i, 1, n) fac[i] = 1ll * fac[i - 1] * i % mod;
  ifac[n] = qpow(fac[n]);
  per(i, n, 1) ifac[i - 1] = 1ll * ifac[i] * i % mod;
}
inline int C(int n, int m) {
  if (n < m || m < 0) return 0;
  return 1ll * fac[n] * ifac[n - m] % mod * ifac[m] % mod;
}

int ie[N][41]; bool used[N];
int cnt[N], l[N], r[N], a[N], b[N], n, m;

int main() {
  init(N - 5);
  n = read(), m = read();
  rep(i, 1, n) {
    l[i] = read(), r[i] = read();
    cnt[l[i]]++, cnt[r[i] + 1]--;
  }
  rep(i, 1, n) {
    cnt[i] += cnt[i - 1];
  }
  rep(i, 0, m - 1) {
    a[i] = read(), b[i] = read();
  }
  int all = 1 << m;
  rep(st, 0, all - 1) {
    int L = 1, R = n, tot = 0;
    rep(i, 0, m - 1) {
      if (st >> i & 1) {
        ckmax(L, l[a[i]]), ckmin(R, r[a[i]]);
        if (!used[a[i]]) tot++, used[a[i]] = 1;
        ckmax(L, l[b[i]]), ckmin(R, r[b[i]]);
        if (!used[b[i]]) tot++, used[b[i]] = 1;
      }
    }
    rep(i, 0, m - 1) {
      if (st >> i & 1) {
        used[a[i]] = used[b[i]] = 0;
      }
    }
    if (L > R) continue;
    int coef = __builtin_popcount(st) & 1 ? -1 : 1;
    ie[L][tot] += coef, ie[R + 1][tot] -= coef;
  } 
  int ans = 0;
  rep(j, 0, 2 * m) {
    rep(i, 1, n) {
      ie[i][j] += ie[i - 1][j];
      ans = (ans + 1ll * ie[i][j] * C(cnt[i] - j, i - j)) % mod;
    }
  }
  print((ans + mod) % mod, '\n');
  return 0;
}