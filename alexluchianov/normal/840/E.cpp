#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 50000;
int const inf = 1000000000;

int const lim = 256;

std::vector<int> g[1 + nmax];
int level[1 + nmax], v[1 + nmax], far[1 + nmax], far2[1 + nmax];
int dp[1 + nmax][1 + lim];

void dfs(int node, int parent) {
  level[node] = level[parent] + 1;
  far[node] = parent;

  for(int h = 0;h < g[node].size(); h++) {
    int to = g[node][h];
    if(to != parent)
      dfs(to, node);
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, q;
  std::cin >> n >> q;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  for(int i = 1;i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1, 0);
  for(int i = 1;i <= n; i++) 
    if(lim <= level[i]) {
      for(int j = 0; j < lim; j++)
        dp[i][j] = -inf;
      int node = i;
      for(int j = 0; j < lim; j++) {
        int val = v[node] / lim;
        int part = v[node] % lim;
        dp[i][val] = std::max(dp[i][val], part ^ j), 
        node = far[node];
      }
      far2[i] = node;
      for(int j = 0; j < 8; j++) {
        for(int mask = 0; mask < lim; mask++) {
          if(mask & (1 << j)) {
            int a = dp[i][mask];
            int b = dp[i][mask ^ (1 << j)];
            dp[i][mask] = std::max(a, b + (1 << (j + 8)));
            dp[i][mask ^ (1 << j)] = std::max(a + (1 << (j + 8)), b);
          }
        }
      }
    }
  for(int i = 1;i <= q; i++) {
    int x, y;
    std::cin >> x >> y;
    int result = 0, part = 0;
    while(level[x] <= level[y] - lim) {
      result = std::max(result, dp[y][part]);
      part++;
      y = far2[y];
    }
    part = (part<<8);
    while(level[x] <= level[y]) {
      result = std::max(result, part ^ v[y]);
      y = far[y];
      part++;
    }
    std::cout << result << '\n';
  }
  return 0;
}