#include <iostream>
#include <vector>

#define int long long

const int MAXN = 100005;
std::vector<int> Adj[MAXN];

int ans = 0;

int dfs(int u, int p) {
  int sz = 1;
  for(int j : Adj[u]) {
    if(j == p)
      continue;

    sz += dfs(j, u);
  }
  if(sz%2 == 0)
    ans++;
  return sz;
}

signed main() {
  int n;
  std::cin >> n;

  if(n%2) {
    std::cout << -1 << std::endl;
    return 0;
  }

  for(int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    u--; v--;
    Adj[u].push_back(v);
    Adj[v].push_back(u);
  }

  dfs(0, -1);
  std::cout << ans-1 << std::endl;

  return 0;
}