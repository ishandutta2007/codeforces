#include <bits/stdc++.h>

using namespace std;

typedef int ll;

struct edge {
  int u, v;
  ll cap, flow;
  edge () {}
  edge (int u, int v, ll cap) : u(u), v(v), cap(cap), flow(0) {}
};

struct Dinic {
  int N;
  vector <edge> E;
  vector <vector <int>> g;
  vector <int> d, pt;
  
  Dinic (int N) : N(N), E(0), g(N), d(N), pt(N) {}

  void AddEdge (int u, int v, ll cap) {
    if (u ^ v) {
      E.emplace_back(u, v, cap);
      g[u].emplace_back(E.size() - 1);
      E.emplace_back(v, u, 0);
      g[v].emplace_back(E.size() - 1);
    }
  }

  bool BFS (int S, int T) {
    queue <int> q({S});
    fill(d.begin(), d.end(), N + 1);
    d[S] = 0;
    while (!q.empty()) {
      int u = q.front(); q.pop();
      if (u == T) break;
      for (int k : g[u]) {
        edge &e = E[k];
        if (e.flow < e.cap and d[e.v] > d[e.u] + 1) {
          d[e.v] = d[e.u] + 1;
          q.emplace(e.v);
        }
      }
    } return d[T] != N + 1;
  }

  ll DFS (int u, int T, ll flow = -1) {
    if (u == T or flow == 0) return flow;
    for (int &i = pt[u]; i < g[u].size(); ++i) {
      edge &e = E[g[u][i]];
      edge &oe = E[g[u][i] ^ 1];
      if (d[e.v] == d[e.u] + 1) {
        ll amt = e.cap - e.flow;
        if (flow != -1 and amt > flow) amt = flow;
        if (ll pushed = DFS(e.v, T, amt)) {
          e.flow += pushed;
          oe.flow -= pushed;
          return pushed;
        }
      }
    } return 0;
  }

  ll MaxFlow (int S, int T) {
    ll total = 0;
    while (BFS(S, T)) {
      fill(pt.begin(), pt.end(), 0);
      while (ll flow = DFS(S, T)) total += flow;
    }
    return total;
  }
};

const int M = 105;
const int N = 3010;
const int INF = 1e9 + 69;

int n, a[N], b[N], last[M];

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) cin >> b[i];
  Dinic dinix(1 + n + 1);
  int src = 0, snk = n + 1;
  for (int i = n; i >= 1; --i) {
    int x = a[i];
    for (int j = x; j < M; j += x) {
      if (last[j]) dinix.AddEdge(last[j], i, INF); 
    }
    last[x] = i;
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (b[i] < 0) dinix.AddEdge(i, snk, -b[i]);
    else ans += b[i], dinix.AddEdge(src, i, b[i]); 
  }
  ans -= dinix.MaxFlow(src, snk);
  cout << ans << '\n';
  return 0;
}