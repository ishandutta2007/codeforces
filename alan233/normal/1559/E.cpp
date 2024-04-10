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

const int N = 100005;
const int mod = 998244353;

int l[N], r[N], n, m;
int l2[N], r2[N], m2;

int dp[51][N], sum[51][N];
int ans[N];

bool vis[N]; int pr[N], len;
void xxs(int n) {
  for (int i = 2; i <= n; i++) {
    if (!vis[i]) pr[++len] = i;
    for (int j = 1; j <= len; j++) {
      if (pr[j] * i > n) break;
      vis[pr[j] * i] = 1;
      if (i % pr[j] == 0) break;
    } 
  }
}

int main() {
  xxs(1e5);
  n = read(), m = read();
  rep(i, 1, n) l[i] = read(), r[i] = read();
  rep(d, 1, m) {
    m2 = m / d;
    dp[0][0] = 1;
    rep(i, 0, m2) sum[0][i] = 1; 
    rep(i, 1, n) {
      l2[i] = (l[i] - 1) / d + 1, r2[i] = r[i] / d;
      rep(j, 1, m2) {
        dp[i][j] = (j - l2[i] >= 0 ? sum[i - 1][j - l2[i]] : 0) - (j - r2[i] - 1 >= 0 ? sum[i - 1][j - r2[i] - 1] : 0);
        dp[i][j] = (dp[i][j] % mod + mod) % mod; 
        sum[i][j] = (sum[i][j - 1] + dp[i][j]) % mod;
      }
    }
    ans[d] = sum[n][m2];
  }  
//  rep(d, 1, m) {
//    D("ans[%d] = %d\n", d, ans[d]);
//  }
  rep(i, 1, len) {
    rep(j, 1, m / pr[i])
      ans[j] = (ans[j] + mod - ans[j * pr[i]]) % mod;
  }
  print(ans[1], '\n');
  return 0;
}