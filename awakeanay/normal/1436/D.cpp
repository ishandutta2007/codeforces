#include <iostream>
#include <vector>

#define MAXN 200005
#define int long long

int n;
int ans = 0;
int a[MAXN];
std::vector<int> Adj[MAXN];

std::pair<int, int> dfs(int u) {
  if(Adj[u].size() == 0) {
    ans = std::max(ans, a[u]);
    return {1, a[u]};
  }

  int sub = a[u];
  int leaves = 0;
  for(int j : Adj[u]) {
    std::pair<int, int> next = dfs(j);
    leaves += next.first;
    sub += next.second;
  }

  ans = std::max(ans, sub/leaves + (sub%leaves != 0));

  return {leaves, sub};
}

signed main() {
  std::cin >> n;

  for(int i = 1; i < n; i++) {
    int u;
    std::cin >> u;
    Adj[u-1].push_back(i);
  }

  for(int i = 0; i < n; i++)
    std::cin >> a[i];

  dfs(0);

  std::cout << ans << std::endl;

  return 0;
}