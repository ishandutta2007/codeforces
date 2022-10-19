#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+5;
const int INF = 1e9;
vector<pair<int, int>> G[N];

bool marked[N][2];
bool done[N];
int d[N][2];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  while (m--) {
    int u, v, t;
    cin >> u >> v >> t;
    G[v].emplace_back(u, t);
  }

  for (int i = 1; i < n; i++) {
    d[i][0] = INF;
    d[i][1] = INF;
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.emplace(0, n);
  while (!pq.empty()) {
    pair<int, int> z = pq.top();
    pq.pop();
    int v = z.second;
    int dist = z.first;
    if (done[v]) continue;
    done[v] = 1;
    for (auto& [u, t]: G[v]) {
      d[u][t] = min(d[u][t], dist+1);
      if (d[u][0] < INF && d[u][1] < INF) {
        pq.emplace(max(d[u][0], d[u][1]), u);
      }
    }
  }

  int dist = max(d[1][0], d[1][1]);
  cout << (dist == INF ? -1 : dist) << '\n';
  for (int i = 1; i <= n; i++) {
    cout << (d[i][0] > d[i][1] ? 0 : 1);
  }
  cout << '\n';
}