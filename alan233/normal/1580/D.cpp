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

const int N = 4005;

ll dp[N][N];
int sz[N], a[N], n, m, tot;

void solve(int &u, int l, int r) {
  if (l > r) { u = 0; return ; } 
  u = ++tot, sz[u] = r - l + 1;
  dp[u][0] = 0;
  dp[u][1] = 1ll * (m - 1) * a[l];
  int pos = l, ls = 0, rs = 0;
  rep(i, l, r) if (a[i] < a[pos]) pos = i;
  solve(ls, l, pos - 1), solve(rs, pos + 1, r);
  if (ls && rs) {
    rep(i, 1, sz[ls]) {
      rep(j, 1, sz[rs]) {
        ckmax(dp[u][i + j], dp[ls][i] + dp[rs][j] - 2ll * a[pos] * i * j);
        ckmax(dp[u][i + j + 1], dp[ls][i] + dp[rs][j] + 1ll * (m - 1) * a[pos] - 2ll * a[pos] * (1ll * i * j + i + j));
      }
    }
  }
  if (ls) {
    rep(i, 0, sz[ls]) {
      ckmax(dp[u][i], dp[ls][i]);
      ckmax(dp[u][i + 1], dp[ls][i] + 1ll * (m - 1) * a[pos] - 2ll * a[pos] * i);
    }
  }
  if (rs) {
    rep(i, 0, sz[rs]) {
      ckmax(dp[u][i], dp[rs][i]);
      ckmax(dp[u][i + 1], dp[rs][i] + 1ll * (m - 1) * a[pos] - 2ll * a[pos] * i);
    }
  }
}

int main() {
  memset(dp, -0x3f, sizeof(dp));
  n = read(), m = read();
  rep(i, 1, n) a[i] = read();
  int rt; solve(rt, 1, n);
  print(dp[rt][m], '\n');
  return 0;
}