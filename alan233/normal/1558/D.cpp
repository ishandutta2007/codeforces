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

const int N = 500005; /* ! */
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
  return 1ll * fac[n] * ifac[n - m] % mod * ifac[m] % mod;
}

struct Fenwick {
  int c[N];
  void add(int x, int dlt) {
    while (x <= 200000) c[x] += dlt, x += x & -x;
  } 
  int qry(int x) {
    int ret = 0;
    while (x) ret += c[x], x ^= x & -x;
    return ret; 
  }
} bit;

int x[N], y[N], lg[N], pos[N], tag[N], n, m;

void solve() {
  n = read(), m = read();
  rep(i, 1, m) x[i] = read(), y[i] = read();
  per(i, m, 1) {
    int now = 0, cur = 0;
    per(j, lg[n], 0) {
      if (now + (1 << j) <= n && cur + bit.c[now + (1 << j)] < y[i])
        now += 1 << j, cur += bit.c[now];
    }
    ++now;
//    printf("i = %d, now = %d, cur = %d\n", i, now, cur);
//    printf("test = %lld\n", bit.qry(now));
    pos[i] = now, bit.add(pos[i], -1);
    tag[pos[i]] = i;
//    printf("pos[%d] = %d\n", i, pos[i]);
  }
  int s = m;
  rep(i, 1, m) {
    if (tag[pos[i] - 1] && tag[pos[i] - 1] < i)
      s--;
  }
  print(C(n + (n - 1 - s), n), '\n');
  rep(i, 1, m) tag[pos[i]] = 0, bit.add(pos[i], 1);
}

int main() {
  init(400000);
  rep(i, 1, 200000) bit.add(i, 1);
  rep(i, 2, 200000) lg[i] = lg[i >> 1] + 1;
  int T = read();
  while (T--) solve();
  return 0;
}