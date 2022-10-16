// Author: wlzhouzhuan
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

const int N = 8005;
const int mod = 1e9 + 7;

inline int qpow(int a, int b = mod - 2) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = 1ll * res * a % mod;
    a = 1ll * a * a % mod, b >>= 1;
  }
  return res;
}

vector<int> adj[N];
int n;

int dp[N][2], coef[N], K;
void dfs1(int u, int fa) {
  dp[u][0] = 1, dp[u][1] = K;
  for (auto v: adj[u]) {
    if (v == fa) continue;
    dfs1(v, u);
    dp[u][1] = (1ll * dp[u][0] * dp[v][1] + 1ll * dp[u][1] * dp[v][0] + 1ll * dp[u][1] * dp[v][1]) % mod;
    dp[u][0] = (1ll * dp[u][0] * dp[v][0] + 1ll * dp[u][0] * dp[v][1]) % mod;
  }
}

int bag[N], fac[N], ifac[N];
int f[N], g[N];
inline void init(int n) {
  fac[0] = 1; rep(i, 1, n) fac[i] = 1ll * fac[i - 1] * i % mod;
  ifac[n] = qpow(fac[n]); per(i, n, 1) ifac[i - 1] = 1ll * ifac[i] * i % mod;
}
inline int C(int n, int m) {
  return 1ll * fac[n] * ifac[n - m] % mod * ifac[m] % mod;
}
inline void Lagrange() {
  bag[0] = 1;
  rep(i, 1, n) {
    per(j, i, 0)
      bag[j] = ((j ? bag[j - 1] : 0) + 1ll * bag[j] * (mod - i)) % mod;
//    rep(j, 0, i) printf("%d ", bag[j]);
//    puts("");
  }
//  rep(i, 0, n) printf("bag[%d] = %d\n", i, bag[i]);
  rep(i, 1, n) {
    int cf = 1ll * coef[i] * ifac[i - 1] % mod * ifac[n - i] % mod;
    if ((n - i) & 1) cf = (mod - cf) % mod;
    int las = 0;
//    printf("i = %d, ", i);
    per(j, n - 1, 0) {
      int now = (bag[j + 1] + 1ll * i * las) % mod;
//      printf("%d ", now);
      f[j] = (f[j] + 1ll * now * cf) % mod;
      las = now;
    }
//    puts("");
  }
}

int main() {
//   freopen("tree.in", "r", stdin);
//   freopen("tree.out", "w", stdout);
  n = read(), init(n);
  rep(i, 1, n - 1) {
    int u = read(), v = read();
    adj[u].pb(v), adj[v].pb(u);
  }
  int invn2 = 1ll * qpow(n) * qpow(n) % mod;
  rep(y, 1, n) {
    K = 1ll * n * qpow(y) % mod;
    dfs1(1, 0);
    coef[y] = 1ll * dp[1][1] * qpow(y, n) % mod * invn2 % mod;
//    printf("coef[%d] = %d\n", y, coef[y]); 
  }
  Lagrange();
//  rep(i, 0, n - 1) printf("%d\n", f[i]);
  rep(i, 0, n - 1) {
    rep(j, 0, i) {
      if ((i - j) & 1) g[j] = (g[j] + mod - 1ll * f[i] * C(i, j) % mod) % mod; 
      else g[j] = (g[j] + 1ll * f[i] * C(i, j)) % mod;
    }
  }
  rep(i, 0, n - 1) print(g[i], " \n"[i == n - 1]);
  return 0;
}