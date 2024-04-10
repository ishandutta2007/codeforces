#include <bits/stdc++.h>
using namespace std;

#define int long long

/*
    U = max capacity
    Complexity: O(V^2 * E)
    O(min(E^{1/2}, V^{2/3}) * E) if U = 1
    O(V^{1/2} * E)$ for bipartite matching.
*/
template <typename flow_t = int>
struct DinicFlow {
  const flow_t INF = numeric_limits<flow_t>::max() / 2;  // 1e9

  int n, s, t;
  vector<vector<int>> adj;
  vector<int> d, cur;
  vector<int> to;
  vector<flow_t> c, f;

  DinicFlow(int n, int s, int t)
      : n(n), s(s), t(t), adj(n, vector<int>()), d(n, -1), cur(n, 0) {}

  int addEdge(int u, int v, flow_t _c) {
    adj[u].push_back(to.size());
    to.push_back(v);
    f.push_back(0);
    c.push_back(_c);
    adj[v].push_back(to.size());
    to.push_back(u);
    f.push_back(0);
    c.push_back(0);
    return (int)to.size() - 2;
  }

  bool bfs() {
    fill(d.begin(), d.end(), -1);
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto edgeId : adj[u]) {
        int v = to[edgeId];
        if (d[v] == -1 && f[edgeId] < c[edgeId]) {
          d[v] = d[u] + 1;
          if (v == t) return 1;
          q.push(v);
        }
      }
    }
    return d[t] != -1;
  }

  flow_t dfs(int u, flow_t res) {
    if (u == t || !res) return res;
    for (int &i = cur[u]; i < adj[u].size(); i++) {
      int edgeId = adj[u][i];
      int v = to[edgeId];
      if (d[v] == d[u] + 1 && f[edgeId] < c[edgeId]) {
        flow_t foo = dfs(v, min(res, c[edgeId] - f[edgeId]));
        if (foo) {
          f[edgeId] += foo;
          f[edgeId ^ 1] -= foo;
          return foo;
        }
      }
    }
    return 0;
  }

  flow_t maxFlow() {
    flow_t res = 0;
    while (bfs()) {
      fill(cur.begin(), cur.end(), 0);
      while (flow_t aug = dfs(s, INF)) res += aug;
    }
    return res;
  }
};

int32_t main() {
  int n;
  cin >> n;
  vector<array<int, 2>> a(n);
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i][0] >> a[i][1] >> w[i];
  }
  DinicFlow<long long> mc(2 * n + 2, 2 * n, 2 * n + 1);
  const int INF = (int)1e9 + 1;
  for (int i = 0; i < n; i++) {
    mc.addEdge(2 * i, 2 * i + 1, w[i]);
  }
  // s -> odd/odd -> even/odd -> even/even -> odd/even

  auto encode = [](array<int, 2> x) {
    if (x[0] % 2 && x[1] % 2) return 0;
    if (x[0] % 2 && !(x[1] % 2)) return 3;
    if (!(x[0] % 2) && !(x[1] % 2)) return 2;
    if (!(x[0] % 2) && x[1] % 2) return 1;
    return -1;
  };

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (abs(a[i][0] - a[j][0]) + abs(a[i][1] - a[j][1]) != 1) continue;
      // auto u = i, v = j;
      // if (encode(a[u]) > encode(a[v])) swap(u, v);
      // mc.addEdge(2 * i + 1, 2 * j, INF);
      // mc.addEdge(2 * j + 1, 2 * i, INF);
      // if (i == 3 && j == 1) cout << encode(a[j]) << ' ' << encode(a[i]) << endl; 
      if (encode(a[j]) - encode(a[i]) == 1) mc.addEdge(2 * i + 1, 2 * j, INF); 
    }
    if (encode(a[i]) == 0) mc.addEdge(2 * n, 2 * i, INF);
    if (encode(a[i]) == 3) mc.addEdge(2 * i + 1, 2 * n + 1, INF);
  }
  cout << accumulate(w.begin(), w.end(), 0LL) - mc.maxFlow() << endl;
}