#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 20000;
std::vector<std::pair<int,int>> g[1 + nmax];
int seen[1 + nmax];
int n;

int dfs(int node, int target) {
  if(seen[node] == 1)
    return 0;
  seen[node] = 1;
  int balance = 0;
  if(node <= n)
    balance = 1;
  else
    balance = -1;

  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h].first;
    if(g[node][h].second <= target)
      balance += dfs(to, target);
  }
  return balance;
}
int solve(int n, int target) {
  for(int i = 1; i <= 2 * n; i++)
    seen[i] = 0;
  for(int i = 1;i <= 2 * n; i++)
    if(dfs(i, target) != 0)
      return 0;
  return 1;
}

int main() {
  int m;
  std::cin >> n >> m;
  for(int i = 1;i <= m; i++) {
    int x, y, cost;
    std::cin >> x >> y >> cost;
    g[x].push_back({n + y, cost});
    g[n + y].push_back({x, cost});
  }
  int x = 0;
  if(solve(n, (1 << 30)) == 0) {
    std::cout << -1;
    return 0;
  }
  for(int jump = (1 << 30); 0 < jump; jump /= 2) 
    if(solve(n, x + jump) == 0)
      x += jump;
  std::cout << x + 1 << '\n';
  return 0;
}