#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using ll = long long;

int const nmax = 100000;
int l[1 + nmax], r[1 + nmax];
ll dp[1 + nmax][2];
std::vector<int> g[1 + nmax];

void dfs(int node, int parent) {
  dp[node][0] = dp[node][1] = 0;
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(to != parent) {
      dfs(to, node);
      dp[node][0] = dp[node][0] + std::max(dp[to][0] + std::abs(l[to] - l[node]), dp[to][1] + std::abs(r[to] - l[node]));
      dp[node][1] = dp[node][1] + std::max(dp[to][0] + std::abs(l[to] - r[node]), dp[to][1] + std::abs(r[to] - r[node]));
    }
  }
  
}

ll solve() {
  int n;
  std::cin >> n;
  for(int i = 1; i <= n; i++)
    g[i].clear();
  for(int i = 1;i <= n; i++)
    std::cin >> l[i] >> r[i];
 
  for(int i = 1;i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1, 0);
  return std::max(dp[1][0], dp[1][1]);
}
int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++) {
    std::cout << solve() << '\n';
  }

  return 0;
}