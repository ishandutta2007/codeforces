#include <bits/stdc++.h>
using namespace std;
const int K = 18;
const int N = 2e5 + 5;
int n, m, q, cur, blk[N], lg[N];
vector<int> g[N], root;
vector<pair<int, int>> e[N];
int dn, dfn[N], low[N], top, stc[N], cn, col[N];
void form(int id) {for(int x = (cn++, 0); x != id; ) col[x = stc[top--]] = cn;}
void tarjan(int id, int eid) {
  dfn[id] = low[id] = ++dn, stc[++top] = id, blk[id] = cur;
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
int dep[N], mi[K][N];
int get(int x, int y) {return dep[x] < dep[y] ? x : y;}
void dfs(int id, int ff) {
  dep[id] = dep[ff] + 1;
  mi[0][dfn[id] = ++dn] = ff;
  for(int it : g[id]) if(it != ff) dfs(it, id);
}
int lca(int u, int v) {
  if(u == v) return u;
  if((u = dfn[u]) > (v = dfn[v])) swap(u, v);
  int d = lg[v - (u++)];
  return get(mi[d][u], mi[d][v - (1 << d) + 1]);
}
int up[N], down[N];
void flush(int id, int ff) {
  for(int it : g[id]) if(it != ff) flush(it, id), up[id] += up[it], down[id] += down[it];
  if(up[id] && down[id]) puts("No"), exit(0);
}
int main() {
#ifdef ALEX_WEI
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);
#endif
  cin >> n >> m >> q;
  for(int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    e[u].push_back({v, i});
    e[v].push_back({u, i});
  }
  for(int i = 1; i <= n; i++) if(!dfn[i]) cur++, tarjan(i, 0);
  for(int i = 1; i <= n; i++)
    for(auto it : e[i])
      if(col[i] != col[it.first])
        g[col[i]].push_back(col[it.first]);
  dn = 0;
  for(int i = 1; i <= cn; i++) if(!dep[i]) dfs(i, 0), root.push_back(i);
  for(int i = 2; i <= cn; i++) lg[i] = lg[i >> 1] + 1;
  for(int i = 1; i <= lg[cn]; i++)
    for(int j = 1; j + (1 << i) - 1 <= cn; j++)
      mi[i][j] = get(mi[i - 1][j], mi[i - 1][j + (1 << i - 1)]);
  for(int i = 1; i <= q; i++) {
    int s, t;
    scanf("%d%d", &s, &t);
    if(blk[s] != blk[t]) puts("No"), exit(0);
    if((s = col[s]) == (t = col[t])) continue; // add this line
    int d = lca(s, t);
    up[s]++, up[d]--, down[t]++, down[d]--;
  }
  for(int it : root) flush(it, 0);
  puts("Yes");
  return cerr << "Time: " << clock() << endl, 0;
}
/*
2022/5/25
start coding at 7:03
finish debugging at 7:20
*/