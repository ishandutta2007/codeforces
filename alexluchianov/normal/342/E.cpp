#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 200000;
int const lgmax = 20;
std::vector<int> g[5 + nmax];

int sz[5 + nmax], seen[5 + nmax];
int dist[1 + lgmax][5 + nmax], far[5 + nmax], depthfar[5 + nmax];

void computesz(int node, int parent) {
  sz[node] = 1;
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(to != parent && seen[to] == 0) {
      computesz(to, node);
      sz[node] += sz[to];
    }
  }
}

int findCentroid(int node, int parent, int target) {
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(to != parent && target <= sz[to] && seen[to] == 0)
      return findCentroid(to, node, target);
  }
  return node;
}

void markdist(int node, int parent, int depth, int level) {
  dist[depth][node] = level;
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(to != parent && seen[to] == 0) {
      markdist(to, node, depth, level + 1);
    }
  }
}

int dp[5 + nmax];

void solve(int root, int depth, int centroidFather) {
  computesz(root, 0);
  int centroid = findCentroid(root, 0, sz[root] / 2);
  far[centroid] = centroidFather;
  depthfar[centroid] = depth;
  
  seen[centroid] = 1;
  markdist(centroid, 0, depth, 0);
  for(int h = 0; h < g[centroid].size(); h++) {
    int to = g[centroid][h];
    if(seen[to] == 0) {
      solve(to, depth + 1, centroid);
    }
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;
  for(int i = 1;i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  solve(1, 0, 0);
  
  for(int i = 1;i <= nmax; i++)
    dp[i] = 1 + n;

  for(int i = 0;i <= m; i++) {
    int op, x;
    
    if(i == 0) {
      op = 1;
      x = 1;
    } else
      std::cin >> op >> x;
    if(op == 1) {
      int start = x;
      while(0 != x) {
        dp[x] = std::min(dp[x], dist[depthfar[x]][start]);
        x = far[x];
      }
    } else {
      int result = n;
      int start = x;
      while(0 != x) {
        result = std::min(result, dp[x] + dist[depthfar[x]][start]);
        x = far[x];
      }
      std::cout << result << '\n';
    }
  }
  return 0;
}