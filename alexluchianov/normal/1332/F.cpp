#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

int const nmax = 300000;
int const modulo = 998244353;
std::vector<int> g[5 + nmax];
int dp[5 + nmax][3];

void dfs(int node, int parent) {
  dp[node][0] = dp[node][2] = 1;
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(to != parent) {
      dfs(to, node);
      dp[node][0] = 1LL * dp[node][0] * (dp[to][0] * 2LL + dp[to][1] * 2 + dp[to][2]) % modulo;
      dp[node][1] = (1LL * dp[node][1] * (dp[to][0] * 2LL + dp[to][1]) + 1LL * dp[node][2] * dp[to][0]) % modulo;
      dp[node][2] = 1LL * dp[node][2] * (dp[to][0] + dp[to][1]) % modulo;
    }
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  for(int i = 1;i < n; i++) {
    int x, y;
    std::cin >> x >> y;

    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1, 0);
  std::cout << (modulo + 1LL * dp[1][0] + dp[1][1] - 1) % modulo << '\n'; 
  return 0;
}