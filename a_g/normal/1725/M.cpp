#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
const long long INF = 1e18;
vector<pair<int, int>> G[2][N];
long long dist[2][N];
bool done[2][N];


int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    dist[0][i] = dist[1][i] = INF;
  }
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    G[0][u].emplace_back(v, w);
    G[1][v].emplace_back(u, w);
  }
  priority_queue<pair<long long, int>> pq;
  dist[0][1] = 0;
  for (int z = 0; z < 2; z++) {
    for (int i = 1; i <= n; i++) {
      if (dist[z][i] != INF) {
        pq.emplace(-dist[z][i], i);
      }
    }
    while (!pq.empty()) {
      int v = pq.top().second;
      pq.pop();
      if (done[z][v]) continue;
      done[z][v] = 1;
      for (auto& [u, w]: G[z][v]) {
        if (dist[z][v]+w < dist[z][u]) {
          dist[z][u] = dist[z][v]+w;
          pq.emplace(-dist[z][u], u);
        }
      }
    }

    if (z == 0) {
      for (int i = 1; i <= n; i++ ){
        dist[1][i] = dist[0][i];
      }
    }
  }

  for (int v = 2; v <= n; v++) {
    cout << (dist[1][v] == INF ? -1 : dist[1][v]) << ' ';
  }
  cout << '\n';
}