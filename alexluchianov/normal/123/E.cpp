#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <iomanip>

using ll = long long;
using ld = long double;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
std::vector<std::vector<int>> g;
int sz[1 + nmax];
ld input[1 + nmax], output[1 + nmax];
ld dp[1 + nmax], dp2[1 + nmax];

void dfs(int node, int parent) {
  sz[node] = 1;
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(to != parent) {
      dfs(to, node);
      sz[node] += sz[to];
      dp[node] += dp[to] + (sz[to] - 1) * output[to];
    }
  }
}

void dfs2(int node, int parent) {
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(to != parent) {
      dp2[to] = (dp[node] - dp[to] - (sz[to] - 1) * output[to] 
               + dp2[node] + (sz[1] - sz[to] - 1) * output[node]);
      dfs2(to, node);
    }
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  g.resize(1 + n);
  for(int i = 1;i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for(int i = 1; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    input[i] = x;
    output[i] = y;
    input[0] += input[i];
    output[0] += output[i];
  }
  for(int i = 1;i <= n; i++) {
    input[i] /= input[0];
    output[i] /= output[0];
  }

  dfs(1, 0);
  dfs2(1, 0);

  ld result = (n - 1);
  for(int i = 1; i <= n; i++)
    result -= input[i] * (dp[i] + dp2[i] + output[i] * (n - 1));
  std::cout << std::setprecision(9) << std::fixed << result << '\n';
  return 0;
}