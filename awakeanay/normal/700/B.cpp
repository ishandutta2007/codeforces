#include <iostream>
#include <vector>

#define int long long

const int MAXN = 200005;

std::vector<int> Adj[MAXN];
int v[MAXN];
int ans = 0;
int k;

int dfs(int u, int p) {
  int cur = v[u];
  for(int j : Adj[u]) {
    if(j == p)
      continue;
    cur += dfs(j, u);
  }

  ans += std::min(cur, 2*k-cur);
  return cur;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n >> k;

  for(int i = 0; i < 2*k; i++) {
    int x;
    std::cin >> x;
    x--;
    v[x] = 1;
  }

  for(int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    u--; v--;
    Adj[u].push_back(v);
    Adj[v].push_back(u);
  }

  dfs(0, -1);
  std::cout << ans << std::endl;

  return 0;
}