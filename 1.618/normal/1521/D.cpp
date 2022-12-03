/*


Q.E.D.

BULB: 20min
result of thinking: Pure. 

f[u]: uu. 
g[u]: uu. 
.
 
start coding: 10:49
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
#define mp make_pair
const int inf = 0x3f3f3f3f;
typedef pair<int, int> P;
int n, f[maxn], g[maxn], cho[maxn][2]; // cho[u][0]: best choice
vector<int> adj[maxn], remain[maxn];
vector<P> del, add;
bool remainVis[maxn];

int calc(int choi) {
  return f[choi] - g[choi] + (choi > 0);
}

void dfs1(int u, int p) { // get f, g.
  int sumg = 0;
  for (auto v : adj[u]) {
    if (v == p)
      continue;
    dfs1(v, u);
    sumg += g[v];
    if (calc(v) > calc(cho[u][0])) {
      cho[u][1] = cho[u][0];
      cho[u][0] = v;
    } else if (calc(v) > calc(cho[u][1])) {
      cho[u][1] = v;
    }
  }
  f[u] = sumg + calc(cho[u][0]);
  g[u] = sumg + calc(cho[u][0]) + calc(cho[u][1]);
}

void dfs2(int u, int p, bool close) { // construction
  for (auto v : adj[u]) {
    if (v == p)
      continue;
    if (v == cho[u][0] || (close && v == cho[u][1])) {
      remain[u].push_back(v);
      remain[v].push_back(u);
      dfs2(v, u, false);
    } else {
      del.push_back(mp(u, v));
      dfs2(v, u, true);
    }
  }
}

int dfs3(int u) { // on G_remain
  remainVis[u] = true;
  for (auto v : remain[u]) {
    if (!remainVis[v])
      return dfs3(v);
  }
  return u;
}

void solve() {
  scanf("%d", &n);
  del.clear(); add.clear();
  for (int i = 1; i <= n; i++) {
    remainVis[i] = false;
    f[i] = g[i] = cho[i][0] = cho[i][1] = 0;
    adj[i].clear();
    remain[i].clear();
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v); 
    adj[v].push_back(u);
  }
  dfs1(1, 0);
  dfs2(1, 0, true);
  for (int i = 1; i <= n; i++) {
    if (!remainVis[i] && remain[i].size() <= 1) {
      add.push_back(mp(i, dfs3(i)));
    }
  }
  printf("%d\n", int(del.size()));
  for (int i = 0; i < (int)del.size(); i++) {
    printf("%d %d %d %d\n", del[i].first, del[i].second,
                            add[i].second, add[i + 1].first);
  }
}
  
int main() {
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}