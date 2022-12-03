/*


Q.E.D.

start thinking:
BULB:
result of thinking:

start coding:
AC:
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> bool chmin(T &x, const T &y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T &x, const T &y) {
  return x < y ? (x = y, true) : false;
}

#define maxn 100005
int n, l[maxn], r[maxn];
vector<int> adj[maxn];
ll f[maxn][2];

void dfs(int u, int p) {
  f[u][0] = f[u][1] = 0;
  for (auto v : adj[u]) {
    if (v == p)
      continue;
    dfs(v, u);
    f[u][0] += max(f[v][0] + abs(l[v] - l[u]), f[v][1] + abs(r[v] - l[u]));
    f[u][1] += max(f[v][0] + abs(l[v] - r[u]), f[v][1] + abs(r[v] - r[u]));
  }
}

void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    adj[i].clear();
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", l + i, r + i);
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 0);
  printf("%lld\n", max(f[1][0], f[1][1]));
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}