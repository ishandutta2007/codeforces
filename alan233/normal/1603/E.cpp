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

const int N = 205;

int fac[N], ifac[N];
int n, mod, ans, a1;
int dp[N][N][45], vis[N][N][45];

inline int qpow(int a, int b = mod - 2) {
  int res = 1;
  while (b) {
    if (b & 1) res = 1ll * res * a % mod;
    a = 1ll * a * a % mod;
    b >>= 1;
  }
  return res;
}

int dfs(int i, int sum, int k) {
  if (i == n) return 1;
  if (!k) return ifac[n - i];
  if (vis[i][sum][k] == a1) return dp[i][sum][k];
  vis[i][sum][k] = a1;
  int &res = dp[i][sum][k]; res = 0;
  int lim = (a1 - sum) / k;
  for (int cnt = 0; cnt <= lim; cnt++) {
    if (k > 1 && i + cnt < n + 1 - a1 - (k - 1)) continue;
    res = (res + 1ll * dfs(i + cnt, sum + cnt * k, k - 1) * ifac[cnt]) % mod;
  }
  return res;
}

int main() {
  n = read(), mod = read();
  fac[0] = ifac[0] = 1;
  rep(i, 1, N - 1) {
    fac[i] = 1ll * fac[i - 1] * i % mod;
    ifac[i] = qpow(fac[i]);
  }
  int lim = 2 * sqrt(n) + 1;
  for (a1 = max(1, n - lim); a1 <= n; a1++) {
    ans = (ans + dfs(0, 0, n + 1 - a1)) % mod;
  }
  print(1ll * fac[n] * ans % mod, '\n');
  return 0;
}