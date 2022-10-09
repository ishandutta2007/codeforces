#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 500000;
int const modulo = 998244353;
int const inv2 = (modulo + 1) / 2;
std::vector<int> g[5 + nmax];
int dp[5 + nmax][2], sz[5 + nmax];
int pow2[5 + nmax];
int n;

void dfs(int node, int parent, ll &result) {
  dp[node][0] = 1;
  dp[node][1] = 0;
  sz[node] = 1;

  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(to != parent) {
      dfs(to, node, result);
      sz[node] += sz[to];
      int a = dp[node][0], b = dp[node][1];
      dp[node][0] = (1LL * a * dp[to][1]) % modulo;
      dp[node][1] = (1LL * a * dp[to][0] + 1LL * b * (dp[to][0] + dp[to][1])) % modulo;
    }
  }
  result = (result + 1LL * dp[node][1] * pow2[n - sz[node] + 1]) % modulo;

  dp[node][1] = (dp[node][0] + 2LL * dp[node][1]) % modulo;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  std::cin >> n;
  pow2[0] = 1;
  for(int i = 1;i <= n; i++)
    pow2[i] = pow2[i - 1] * 2 % modulo;
  
  for(int i = 1; i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  ll result = 0;
  dfs(1, 0, result);
  std::cout << result << '\n';
  return 0;
}