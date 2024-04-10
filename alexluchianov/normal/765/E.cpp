#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 200000;
std::vector<int> g[5 + nmax];

void getDist(int node, int parent, std::vector<int> &dist) {
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(to != parent) {
      dist[to] = dist[node] + 1;
      getDist(to, node, dist);
    }
  }
}

int getMax(int n, std::vector<int> &dist) {
  int node = 1;
  for(int i = 1; i <= n; i++)
    if(dist[node] < dist[i])
      node = i;
 return node;
}

int dfs(int node, int parent) {
  int result = 0;
  for(int h = 0;h < g[node].size(); h++) {
    int to = g[node][h];
    if(to != parent) {
      int res = dfs(to, node);
      if(res == -1)
        return -1;
      if(result == 0)
        result = res;
      else if(result != res)
        return -1;
    }
  }
  return result + 1;
}

int main() {
  int n;
  std::cin >> n;
  for(int i = 1;i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<int> dist(1 + n), dist2(1 + n), dist3(1 + n);
  getDist(1, 0, dist);
  int start = getMax(n, dist);

  getDist(start, 0, dist2);
  int stop = getMax(n, dist2);
  getDist(stop, 0, dist3);
  int l = dist2[stop], root = 0;
  
  for(int i = 1; i <= n; i++) {
    if(dist2[i] + dist3[i] == l && dist2[i] == (l / 2)) {
      root = i;
    }
  }
  std::vector<int> sol;
  for(int i = 0; i < g[root].size(); i++) {
    sol.push_back(dfs(g[root][i], root));
  }

  std::sort(sol.begin(), sol.end());
  sol.erase(std::unique(sol.begin(), sol.end()), sol.end());
  
  if(sol[0] == -1 || 2 < sol.size()) {
    std::cout << -1 << '\n';
    return 0;
  } else {
    int result = 1;
    for(int i = 0; i < sol.size(); i++)
      result += sol[i];
    while(1 < result && result % 2 == 1) {
      result = (result + 1) / 2;
    }
    std::cout << result - 1 << '\n';
  }
  return 0;
}