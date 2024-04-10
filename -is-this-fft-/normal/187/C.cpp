#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_N = 1e5 + 5;

vector<int> adj [MAX_N];
int dist [MAX_N];
int cls [MAX_N];

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
  for (int i = 0; i < MAX_N; i++) {
    root[i] = i;
  }
  
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m, K;
  cin >> n >> m >> K;

  vector<int> special (K);
  for (int i = 0; i < K; i++) {
    cin >> special[i];
  }
  
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int s, t;
  cin >> s >> t;

  special.push_back(t);

  for (int i = 1; i <= n; i++) {
    dist[i] = MAX_N;
  }

  queue<int> Q;
  for (int u : special) {
    if (dist[u] == MAX_N) {
      dist[u] = 0;
      cls[u] = u;
      Q.push(u);
    }
  }

  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();

    for (int nxt : adj[u]) {
      if (dist[nxt] == MAX_N) {
        dist[nxt] = dist[u] + 1;
        cls[nxt] = cls[u];
        Q.push(nxt);
      }
    }
  }

  vector<pair<int, pair<int, int>>> eds;
  for (int i = 1; i <= n; i++) {
    for (int v : adj[i]) {
      if (i >= v) continue;
      if (cls[i] != cls[v]) {
        eds.push_back(make_pair(dist[i] + dist[v] + 1, make_pair(cls[i], cls[v])));
      }
    }
  }

  sort(eds.begin(), eds.end());
  for (auto e : eds) {
    merge(e.second.first, e.second.second);
    if (find(s) == find(t)) {
      cout << e.first << endl;
      return 0;
    }
  }

  cout << -1 << endl;
}