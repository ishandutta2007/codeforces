#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool Mbe;
constexpr int N = 600 + 5;
constexpr int M = 1e5 + 5;
struct flow {
  int cnt = 1, hd[N], nxt[M << 1], to[M << 1];
  ll limit[M << 1];
  void add(int u, int v, ll w) {
    // cout << u << " " << v << " " << w << endl;
    nxt[++cnt] = hd[u], hd[u] = cnt, to[cnt] = v, limit[cnt] = w;
    nxt[++cnt] = hd[v], hd[v] = cnt, to[cnt] = u, limit[cnt] = 0;
  }
  int dis[N], cur[N], T;
  ll dfs(int id, ll res) {
    if(id == T) return res;
    ll flow = 0;
    for(int i = cur[id]; i && res; i = nxt[i]) {
      int it = to[i];
      ll c = min(res, (ll) limit[i]);
      cur[id] = i;
      if(dis[id] + 1 == dis[it] && c) {
        ll k = dfs(it, c);
        flow += k, res -= k, limit[i] -= k, limit[i ^ 1] += k;
      }
    }
    if(!flow) dis[id] = -1;
    return flow;
  }
  ll maxflow(int s, int t) {
    ll flow = 0;
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
      flow += dfs(s, 1e18);
    }
  }
} g;
int n, t;
bool Med;
int main() {
  fprintf(stderr, "%.4lf\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
  #endif
  cin >> n, t = n * 2 + 1;
  ll ans = 0;
  for(int i = 1; i <= n; i++) {
    int s, x;
    cin >> s;
    while(s--) cin >> x, g.add(i, x + n, 1e18);
  }
  for(int i = 1; i <= n; i++) g.add(i + n, t, 1e9);
  for(int i = 1; i <= n; i++) {
    int p;
    cin >> p, p = -p, ans += p += 1e9;
    g.add(0, i, p);
  }
  // cout << ans << endl;
  cout << -(ans - g.maxflow(0, t)) << "\n";
  return cerr << "Time: " << clock() << "\n", 0;
}
/*
2022/7/7
start coding at 7:44
finish debugging at 7:57
*/