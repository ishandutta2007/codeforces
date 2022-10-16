#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e4 + 5;
constexpr int M = 2e4 + 5;
struct flow {
  int cnt = 1, hd[N], nxt[M << 1], to[M << 1], limit[M << 1];
  void add(int u, int v, int w) {
    nxt[++cnt] = hd[u], hd[u] = cnt, to[cnt] = v, limit[cnt] = w;
    nxt[++cnt] = hd[v], hd[v] = cnt, to[cnt] = u, limit[cnt] = 0;
  }
  int T, dis[N], cur[N];
  int dfs(int id, int res) {
    if(id == T) return res;
    int flow = 0;
    for(int i = cur[id]; i && res; i = nxt[i]) {
      cur[id] = i;
      int it = to[i], c = min(limit[i], res);
      if(dis[id] + 1 == dis[it] && c) {
        int k = dfs(it, c);
        flow += k, res -= k, limit[i] -= k, limit[i ^ 1] += k;
      }
    }
    if(!flow) dis[id] = -1;
    return flow;
  }
  int maxflow(int s, int t) {
    int flow = 0;
    T = t;
    while(1) {
      queue<int> q;
      memcpy(cur, hd, sizeof(cur));
      memset(dis, -1, sizeof(dis));
      q.push(s), dis[s] = 0;
      while(!q.empty()) { 
        int t = q.front();
        q.pop();
        for(int i = hd[t]; i; i = nxt[i])
          if(dis[to[i]] == -1 && limit[i])
            dis[to[i]] = dis[t] + 1, q.push(to[i]);
      }
      if(dis[t] == -1) return flow;
      flow += dfs(s, 1e9);
    }
  }
} g;
int n, m, d, t, p[N], c[N], k[N], vis[N], ans[N];
int main() {
#ifdef ALEX_WEI
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);
#endif
  cin >> n >> m, t = n + m + 1;
  for(int i = 1; i <= m; i++) g.add(n + i, t, 1);
  for(int i = 1; i <= n; i++) cin >> p[i];
  for(int i = 1; i <= n; i++) cin >> c[i];
  cin >> d;
  for(int i = 1; i <= d; i++) cin >> k[i], vis[k[i]] = 1;
  for(int i = 1; i <= n; i++)
    if(!vis[i]) {
      if(p[i] >= n) continue;
      g.add(p[i] + 1, n + c[i], 1);
    }
  g.add(0, 1, 1);
  for(int i = d, cur = 0; i; i--) {
    while(g.maxflow(0, t)) if(++cur < n) g.add(0, cur + 1, 1);
    ans[i] = cur;
    if(p[k[i]] < n) g.add(p[k[i]] + 1, n + c[k[i]], 1);
  }
  for(int i = 1; i <= d; i++) printf("%d\n", ans[i]);
  return 0;
}
/*
2022/6/10
start thinking at
start coding at 20:48
finish debugging at 21:01
*/