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

const int N = 405;

int T, mod;

int fac[N], f[N], g[N], h[N][N];
void init(int n) {
  fac[0] = 1; rep(i, 1, n) fac[i] = 1ll * fac[i - 1] * i % mod;
  rep(i, 1, n) {
    g[i] = fac[i];
    rep(j, 1, i - 1)
      g[i] = (g[i] + mod - 1ll * g[j] * fac[i - j] % mod) % mod;
  }
  h[0][0] = 1;
  rep(i, 1, n) {
    rep(j, 1, i) {
      rep(k, 1, i) {
        h[i][j] = (h[i][j] + 1ll * h[i - k][j - 1] * fac[k]) % mod;
      }
    }
  }
  f[1] = 1, f[2] = 2;
  rep(i, 3, n) {
    f[i] = fac[i];
    int minus1 = 0, minus2 = 0;
    rep(j, 1, i - 1) minus1 = (minus1 + 1ll * g[j] * fac[i - j]) % mod;
    rep(j, 3, i - 1) minus2 = (minus2 + 1ll * h[i][j] * f[j]) % mod;
    f[i] = (f[i] + 3ll * mod - 2 * minus1 - minus2) % mod;
  }
}

int main() {
  T = read(), mod = read(), init(400);
  while (T--) {
    int n = read();
    print(f[n], '\n');
  }
  return 0;
}