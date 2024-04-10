#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 200000;
std::vector<int> g[1 + nmax];
int dp[1 + nmax], in_stack[1 + nmax];

int dfs(int node) {
  in_stack[node] = 1;
  dp[node] = 1;
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(in_stack[to] == 1)
      return -1;
    else if(dp[to] == 0) {
      if(dfs(to) == -1)
        return -1;
    }
    if(to < node)
      dp[node] = std::max(dp[node], dp[to]);
    else
      dp[node] = std::max(dp[node], dp[to] + 1);
  }
  in_stack[node] = 0;
  return 0;
}

int solve() {
  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++)
    g[i].clear();
  for(int i = 1;i <= n; i++) {
    int k;
    std::cin >> k;
    for(int j = 1;j <= k; j++) {
      int val;
      std::cin >> val;
      g[i].push_back(val);
    }
  }
  for(int i = 1;i <= n; i++)
    dp[i] = in_stack[i] = 0;
  for(int i = 1;i <= n; i++)
    if(dp[i] == 0 && dfs(i) == -1)
      return -1;
  int result = 0;
  for(int i = 1;i <= n; i++)
    result = std::max(result, dp[i]);
  return result;
}


int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    std::cout << solve() << '\n';
  return 0;
}