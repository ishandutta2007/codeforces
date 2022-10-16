#include <bits/stdc++.h>
using namespace std;
constexpr int N = 4e5 + 5;
constexpr int M = 6e5 + 5;
struct flow {
  int cnt = 1, hd[N], nxt[M << 1], to[M << 1], limit[M << 1];
  void add(int u, int v, int w) {
    nxt[++cnt] = hd[u], hd[u] = cnt, to[cnt] = v, limit[cnt] = w;
    nxt[++cnt] = hd[v], hd[v] = cnt, to[cnt] = u, limit[cnt] = 0;
  }
  int dis[N], cur[N], T;
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
      memset(dis, -1, sizeof(dis));
      memcpy(cur, hd, sizeof(cur));
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
} g, h;
long long sum[N];
int n1, n2, m, q, I, IC, u[N], v[N], bel[N], L[N], R[N], eid[N];
map<pair<int, int>, int> mp;
int sgn(int id) {return id > 0;}
int main() {
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  cin >> n1 >> n2 >> m >> q;
  int t = n1 + n2 + 1;
  for(int i = 1; i <= m; i++) cin >> u[i] >> v[i], v[i] += n1;
  for(int i = 1; i <= n1; i++) g.add(0, i, 1);
  for(int i = 1; i <= n2; i++) g.add(n1 + i, t, 1);
  for(int i = 1; i <= m; i++) g.add(u[i], v[i], 1e9);
  int J = g.maxflow(0, t);
  for(int i = 1; i <= n1; i++) 
    if(g.dis[i] != -1) R[++I] = i, bel[i] = -I;
    else L[++IC] = i, bel[i] = IC;
  for(int i = 1; i <= n2; i++)
    if(g.dis[n1 + i] == -1) R[++I] = -i, bel[n1 + i] = -I;
    else L[++IC] = -i, bel[n1 + i] = IC;
  assert(IC == J);
  for(int i = 1; i <= IC; i++) h.add(0, i, 1);
  for(int i = 1; i <= I; i++) h.add(IC + i, t, 1);
  for(int i = 1; i <= m; i++) {
    if(sgn(bel[u[i]]) == sgn(bel[v[i]])) continue;
    u[i] = bel[u[i]], v[i] = bel[v[i]];
    if(u[i] < 0) swap(u[i], v[i]);
    mp[{u[i], IC - v[i]}] = i;
    h.add(u[i], IC - v[i], 1);
  }
  assert(h.maxflow(0, t) == J);
  for(int i = 1; i <= IC; i++)
    for(int j = h.hd[i]; j; j = h.nxt[j]) {
      int it = h.to[j];
      if(it <= IC || h.limit[j]) continue;
      assert(!eid[i]);
      eid[i] = mp[{i, it}];
      sum[i] = sum[i - 1] + eid[i];
    }
  int curflow = J;
  for(int i = 1; i <= q; i++) {
    int type;
    cin >> type;
    if(type == 1) {
      cout << "1\n";
      cout << L[curflow] << "\n";
      cout << sum[--curflow] << "\n";
    }
    else {
      cout << curflow << "\n";
      for(int j = 1; j <= curflow; j++) cout << eid[j] << " ";
      cout << "\n";
    }
    fflush(stdout);
  }
  return 0;
}