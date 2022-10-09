#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
int v[1 + nmax];
std::vector<int> g[1 + nmax];
int dp[1 + nmax][2];

void dfs(int node, int parent, int &aux) {
  dp[node][0] = dp[node][1] = 0;
  if(0 < v[node])
    dp[node][v[node] - 1] = 1;
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(to != parent) {
      dfs(to, node, aux);
      for(int h = 0; h < 2; h++)
        aux = std::max(aux, dp[node][h] + dp[to][!h]);
      for(int h = 0; h < 2;h++)
        dp[node][h] = std::max(dp[node][h], dp[to][h]);

      if(0 < v[node])
        dp[node][v[node] - 1] = std::max(dp[node][v[node] - 1], dp[to][!(v[node] - 1)] + 1);
    }
  }
}

void solve() {
  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  for(int i = 1;i <= n; i++)
    g[i].clear();

  for(int i = 1;i < n;i++){
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int aux = 0;
  dfs(1, 0, aux);
  std::cout << aux / 2 + 1 << '\n';
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}