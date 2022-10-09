#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 200000;
int edges[1 + nmax][2];
std::vector<int> g[1 + nmax];
int sol[1 + nmax * 2];

void dfs(int node) {
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(sol[to] == 0) {
      sol[to] = 3 - sol[node];
      dfs(to);
    }
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++) {
    std::cin >> edges[i][0] >> edges[i][1];
    g[edges[i][0]].push_back(edges[i][1]);
    g[edges[i][1]].push_back(edges[i][0]);
  }
  for(int i = 1;i <= 2 * n; i += 2) {
    g[i].push_back(i + 1);
    g[i + 1].push_back(i);
  }
  for(int i = 1; i <= 2 * n; i++) {
    if(0 == sol[i]) {
      sol[i] = 1;
      dfs(i);
    }
  }
  for(int i = 1; i <= n; i++)
    std::cout << sol[edges[i][0]] << " " << sol[edges[i][1]] << '\n';
  return 0;
}