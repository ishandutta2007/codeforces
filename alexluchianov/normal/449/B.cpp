#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <queue>

using ll = long long;

int const nmax = 100000;
ll const inf = 1000000000000000000;
std::vector<std::pair<int, int>> g[5 + nmax];
ll dist[5 + nmax], best[5 + nmax];

void dijkstra(int n) {
  std::priority_queue<std::pair<ll,int>, std::vector<std::pair<ll, int>>,
                      std::greater<std::pair<ll,int>>> pq;
  pq.push({0, 1}); 
  
  for(int i = 1; i <= n; i++)
    dist[i] = inf;
  dist[1] = 0;
  while(0 < pq.size()) {
    int node = pq.top().second;
    ll base = pq.top().first;
    pq.pop();
    if(dist[node] != base)
      continue;
    for(int h = 0; h < g[node].size(); h++) {
      int to = g[node][h].first;
      int cost = g[node][h].second;
      if(dist[node] + cost < dist[to]) {
        dist[to] = dist[node] + cost;
        best[to] = cost;
        pq.push({dist[to], to});
      } else if(dist[node] + cost == dist[to]) {
        if(cost % 2 == 0)
          best[to] = cost;
      }
    }
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m, k;
  std::cin >> n >> m >> k;
  for(int i = 1;i <= m; i++) {
    int x, y, cost;
    std::cin >> x >> y >> cost;
    g[x].push_back({y, 2 * cost});
    g[y].push_back({x, 2 * cost});
  }
  
  for(int i = 1;i <= k; i++) {
    int pos, val;
    std::cin >> pos >> val;
    g[1].push_back({pos, 2 * val + 1});
  }
  int result = k;
  dijkstra(n);
  for(int i = 1;i <= n; i++)
    result -= best[i] % 2;

  std::cout << result << '\n';
  return 0;
}