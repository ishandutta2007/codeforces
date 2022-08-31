#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

template<typename T>
using ipq = priority_queue<T, vector<T>, greater<T>>;

typedef long long ll;

const ll INF = 1e18 + 2000;
const int MAX_N = 1e5 + 5;

vector<pair<int, ll>> adj [MAX_N]; // vtx, length
int clp [MAX_N];
ll dist [MAX_N];
bool vis [MAX_N];

int root [MAX_N];
int find (int u) {
  if (root[u] != u) {
    root[u] = find(root[u]);
  }
  return root[u];
}

void merge (int u, int v) {
  u = find(u);
  v = find(v);
  root[u] = v;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;

    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  int K;
  cin >> K;

  vector<int> portals (K);
  for (int i = 0; i < K; i++) {
    cin >> portals[i];
  }

  for (int i = 1; i <= n; i++) {
    dist[i] = INF;
  }
  
  ipq<pair<ll, int>> Q;
  for (int p : portals) {
    dist[p] = 0;
    clp[p] = p;
    Q.push({dist[p], p});
  }

  while (!Q.empty()) {
    auto pr = Q.top();
    Q.pop();

    int cur = pr.second;
    if (vis[cur]) {
      continue;
    }

    vis[cur] = true;
    for (auto e : adj[cur]) {
      ll w = e.second;
      int nxt = e.first;

      if (dist[nxt] > dist[cur] + w) {
        dist[nxt] = dist[cur] + w;
        clp[nxt] = clp[cur];
        Q.push({dist[nxt], nxt});
      }
    }
  }

  map<pair<int, int>, ll> port_eds;
  for (int u = 1; u <= n; u++) {
    for (auto e : adj[u]) {
      int v = e.first;
      ll w = e.second;

      if (clp[u] == clp[v]) {
        continue;
      }

      int p = clp[u];
      int q = clp[v];
      ll pqw = dist[u] + dist[v] + w;
      if (p > q) swap(p, q);
      if (!port_eds.count({p, q})) {
        port_eds[{p, q}] = pqw;
      } else {
        port_eds[{p, q}] = min(port_eds[{p, q}], pqw);
      }
    }
  }

  vector<pair<ll, pair<int, int>>> port_eds_ord;
  for (auto pr : port_eds) {
    port_eds_ord.push_back(make_pair(pr.second, pr.first));
  }

  ll ans = 0;
  for (int p : portals) {
    root[p] = p;
  }
  sort(port_eds_ord.begin(), port_eds_ord.end());
  for (auto e : port_eds_ord) {
    ll w = e.first;
    int u = e.second.first;
    int v = e.second.second;

    if (find(u) != find(v)) {
      ans += w;
      merge(u, v);
    }
  }

  cout << ans + dist[1] << endl;
}