#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 200000;
std::vector<int> g[5 + nmax];

int v[5 + nmax];
int leaf[5 + nmax], dp[5 + nmax];

int dfs(int node, int parent, int &target) {
  int base = (target <= v[node]);
  leaf[node] = base;
  dp[node] = 0;
  int smax = 0, result = 0;

  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(to != parent) {
      result = std::max(result, dfs(to, node, target));

      if(0 < base && 0 < dp[to]) {
        if(leaf[to] == 1)
          base += dp[to];
        else
          leaf[node] = 0;
        if(leaf[to] == 0 && leaf[node] == 0) {
          smax = std::max(smax, dp[node] + dp[to]);
          dp[node] = std::max(dp[node], dp[to]);
        }
      } else
        leaf[node] = 0;
    }
  }

  dp[node] = dp[node] + base;
  return std::max(result, smax + base);
}

int solve(int n, int target) {
  int root = -1;
  for(int i = 1;i <= n; i++)
    if(v[i] < target)
      root = i;
  return dfs(root, 0, target);
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, k;
  std::cin >> n >> k;
  int smin = -1;
  for(int i = 1;i <= n; i++) {
    std::cin >> v[i];
    if(smin == -1)
      smin = v[i];
    else
      smin = std::min(smin, v[i]);
  }
  for(int i = 1;i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  for(int jump = (1 << 20); 0 < jump; jump /= 2)
    if(k <= solve(n, smin + jump))
      smin += jump;
  std::cout << smin << '\n';
  return 0;
}