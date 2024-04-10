#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
int n, m;
vector<pair<int, int>> e[N];
vector<int> g[N];
int dn, dfn[N], low[N], top, stc[N], cn, col[N];
void form(int id) {cn++; for(int x = 0; x != id; ) col[x = stc[top--]] = cn;}
void tarjan(int id, int eid) {
  stc[++top] = id, dfn[id] = low[id] = ++dn;
  for(auto _ : e[id]) {
    if(_.second == eid) continue;
    int it = _.first;
    if(!dfn[it]) {
      tarjan(it, _.second), low[id] = min(low[id], low[it]);
      if(low[it] > dfn[id]) form(it);
    }
    else low[id] = min(low[id], dfn[it]);
  }
  if(!eid) form(id);
}
int ans, comp, vis[N], dis[N];
vector<int> cur;
void find(int id) {
  cur.push_back(id), vis[id] = 1;
  for(int it : g[id]) if(!vis[it]) find(it);
}
void dfs(int id, int ff) {
  dis[id] = dis[ff] + 1;
  for(int it : g[id]) if(it != ff) dfs(it, id);
}
void deal(int id) {
  if(g[id].empty()) return ans++, void();
  cur.clear(), find(id);
  dfs(id, 0);
  int u = id, leaf = 0;
  for(int it : cur) if(dis[it] > dis[u]) u = it;
  dfs(u, 0);
  for(int it : cur) if(dis[it] > dis[u]) u = it;
  for(int it : cur) leaf += g[it].size() == 1;
  ans += dis[u] + leaf - 2;
}
int main() {
#ifdef ALEX_WEI
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);
#endif
  cin >> n >> m;
  for(int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    e[u].push_back({v, i});
    e[v].push_back({u, i});
  }
  for(int i = 1; i <= n; i++) if(!dfn[i]) tarjan(i, 0);
  for(int i = 1; i <= n; i++)
    for(auto _ : e[i])
      if(col[i] != col[_.first])
        g[col[i]].push_back(col[_.first]);
  for(int i = 1; i <= n; i++) if(!vis[i]) deal(i), comp++;
  cout << n - ans + comp - 1 << endl;
  return cerr << "Time: " << clock() << endl, 0;
}
/*
2022/5/25
start coding at 6:41
finish debugging at 7:00
*/