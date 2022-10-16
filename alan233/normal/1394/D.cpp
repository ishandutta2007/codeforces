// Author: wlzhouzhuan
#include <bits/stdc++.h>
using namespace std;

#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define SZ(x) (int(x.size()))
#define fir first
#define sec second

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

const int N = 200005;

vector<int> adj[N];
int n, val[N], h[N];

/*
dp[u][0]: u  fa[u]
dp[u][1]: fa[u]  u 
*/
ll dp[N][2];
ll gao(int u, int a, int b, int c, ll res, vector<ll> tmp) {
  ll qwq = 1e18;
  b += c;
  ckmin(qwq, 1ll * max(a, b) * val[u] + res);
  for (int i = 1; i <= c; i++) {
    a++, b--, res += tmp[i - 1];
    ckmin(qwq, 1ll * max(a, b) * val[u] + res);
  }
  return qwq;
}
void dfs(int u, int fa) {
  int a = 0, b = 0, c = 0;
  ll res = 0;
  vector<ll> tmp;
  for (auto v: adj[u]) {
    if (v == fa) continue;
    dfs(v, u);
    if (h[v] > h[u]) a++, res += dp[v][0];
    else if (h[v] < h[u]) b++, res += dp[v][1];
    else c++, res += dp[v][1], tmp.pb(dp[v][0] - dp[v][1]);
  }
  sort(tmp.begin(), tmp.end());
  if (u == 1) { //  
    dp[u][0] = gao(u, a, b, c, res, tmp);
  } else {
    if (h[u] >= h[fa]) dp[u][0] = gao(u, a, b + 1, c, res, tmp);
    if (h[u] <= h[fa]) dp[u][1] = gao(u, a + 1, b, c, res, tmp);
  }
}

int main() {
//  memset(dp, 0x3f, sizeof(dp));
  n = read();
  rep(i, 1, n) val[i] = read();
  rep(i, 1, n) h[i] = read();
  rep(i, 1, n - 1) {
    int u = read(), v = read();
    adj[u].pb(v), adj[v].pb(u);
  }
  dfs(1, 0);
  print(dp[1][0], '\n');
  return 0;
}