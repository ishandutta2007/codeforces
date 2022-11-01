#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 200010;
const ll INF = 1e16 + 69;

int n, m; ll d[N][4];
vector <pair <int, ll>> g[N];

int main() {
  cin >> n >> m;
  while (m--) {
    int u, v; ll w;
    scanf("%d %d %lld", &u, &v, &w);
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 4; ++j) d[i][j] = INF;
  }
  priority_queue <tuple <ll, int, int>> pq;
  pq.emplace(0, 1, 0); d[1][0] = 0;
  while (!pq.empty()) {
    auto [dist, u, mask] = pq.top();
    pq.pop(); dist = -dist;
    if (d[u][mask] < dist) continue;
    for (auto [v, w] : g[u]) {
      if (d[v][mask] > d[u][mask] + w) {
        d[v][mask] = d[u][mask] + w;
        pq.emplace(-d[v][mask], v, mask);
      }
      if ((~mask & 1) and d[v][mask | 1] > d[u][mask] + 2 * w) {
        d[v][mask | 1] = d[u][mask] + 2 * w;
        pq.emplace(-d[v][mask | 1], v, mask | 1);
      }
      if ((~mask & 2) and d[v][mask | 2] > d[u][mask]) {
        d[v][mask | 2] = d[u][mask];
        pq.emplace(-d[v][mask | 2], v, mask | 2);
      }
    }
  }
  for (int i = 2; i <= n; ++i) {
    ll cur = min({d[i][0], d[i][1], d[i][3]});
    printf("%lld ", cur);
  }
  cout << '\n';
  return 0;
}