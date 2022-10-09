#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 300000;
ll const inf = 1000000000000000000;
std::vector<std::pair<int, int>> g[5 + nmax];
int far[5 + nmax], sz[5 + nmax], bonus[5 + nmax];
ll dist[5 + nmax];

void dfs(int node, int parent) {
  sz[node] = 1;
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h].first;
    int cost = g[node][h].second;
    if(to != parent) {
      far[to] = node;
      dist[to] = dist[node] + cost;
      dfs(to, node);
      sz[node] += sz[to];
    }
  }
}

int solve(int n) {
  if(3 <= sz[n])
    return 0;
  
  for(int start = n; start != 1; start = far[start])
    if(3 <= sz[far[start]] - sz[start])
      return 0;
  
  for(int i = 2;i < n; i++)
    if(sz[i] == 1)
      bonus[far[i]] = dist[i] - dist[far[i]];

  ll result = 2 * inf;
  ll smin = 2 * inf;
  

  for(int start = n; start != 0; start = far[start]) {
    int father = far[start];
    if(father != 1 && father != 0)
      result = std::min(result, dist[start] - dist[far[father]]);

    if(father != 0) {
      if(0 < bonus[start])
        result = std::min(result, dist[start] - dist[father] - bonus[start]);
      if(0 < bonus[father])
        result = std::min(result, dist[start] - dist[father] - bonus[father]);
    }

    if(0 < bonus[start]) {
      result = std::min(result, -dist[start] + smin - bonus[start]);
      smin = std::min(smin, dist[start] - bonus[start]);
    }
  }
  return result;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, q;
  std::cin >> n >> q;
  for(int i = 1;i < n; i++) {
    int x, y, cost;
    std::cin >> x >> y >> cost;
    g[x].push_back({y, cost});
    g[y].push_back({x, cost});
  }
  dfs(1, 0);
  int result = solve(n);
  for(int i = 1;i <= q; i++) {
    int val;
    std::cin >> val;
    std::cout << dist[n] - std::max(0, result - val) << '\n';
  }
  return 0;
}