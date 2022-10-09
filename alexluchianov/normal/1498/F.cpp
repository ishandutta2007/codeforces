#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 100000;
int const kmax = 60;
std::vector<int> g[5 + nmax];
int v[5 + nmax];
int dp[5 + nmax][kmax] = {0}, dp2[5 + nmax][kmax] = {0};
int k;

void dfs(int node, int parent) {
  dp[node][0] = v[node];
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(to != parent) {
      dfs(to, node);
      for(int h = 0; h < 2 * k; h++)
        dp[node][(h + 1) % (2 * k)] ^= dp[to][h];
    }
  }
}

void dfs2(int node, int parent) {
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(to != parent) {
      for(int h = 0; h < 2 * k; h++)
        dp2[to][(h + 1) % (2 * k)] ^= dp2[node][h] ^ dp[node][h] ^ dp[to][(2 * k + h - 1) % (2 * k)];
      dfs2(to, node);
    }
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n >> k;
  for(int i = 1;i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  dfs(1, 0);
  dfs2(1, 0);
  for(int i = 1; i <= n; i++) {
    int result = 0;
    for(int j = k; j < 2 * k; j++)
      result ^= dp[i][j] ^ dp2[i][j];
    std::cout << (0 < result) << " ";
  }
  std::cout << '\n';
  return 0;
}