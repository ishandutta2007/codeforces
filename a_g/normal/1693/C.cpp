#include <bits/stdc++.h>
using namespace std;

// source: editorial

const int N = 2e5+5;
const int INF = 1e9;
vector<int> G[N];
int dist[N], d[N];
bool done[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    G[v].push_back(u);
    d[u]++;
  }
  
  fill(dist+1, dist+n+1, INF);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.emplace(0, n);
  dist[n] = 0;
  while (!pq.empty()) {
    pair<int, int> z = pq.top();
    pq.pop();
    int v = z.second;
    if (done[v]) continue;
    done[v] = 1;
    for (int u: G[v]) {
      int k = dist[v] + d[u];
      if (k < dist[u]) {
        dist[u] = k;
        pq.emplace(k, u);
      }
      d[u]--;
    }
  }

  cout << dist[1] << '\n';


}