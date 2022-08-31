#include <iostream>
#include <vector>

#define int long long

const int MAXN = 200005;

std::vector<int> Adj[MAXN];
std::vector<int> mark;
std::vector<int> deg;
int ans;

void dfs(int u) {
  mark[u]++;
  if(deg[u] > 2) {
    ans--;
    return;
  }

  for(int j : Adj[u]) {
    if(!mark[j])
      dfs(j);
  }
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    if(n == 1) {
      std::cout << 0 << std::endl;
      continue;
    }
    for(int i = 0; i < n; i++)
      Adj[i].clear();
    deg = mark = std::vector<int>(n, 0);

    for(int i = 1; i < n; i++) {
      int u, v;
      std::cin >> u >> v;
      u--; v--;
      deg[u]++;
      deg[v]++;
      Adj[u].push_back(v);
      Adj[v].push_back(u);
    }

    ans = 0;
    for(int i = 0; i < n; i++) {
      if(deg[i] == 1)
        ans++;
    }

    if(ans == 2) {
      std::cout << 1 << std::endl;
      continue;
    }

    for(int i = 0; i < n; i++) {
      if(deg[i] == 1)
        dfs(i);
    }

    std::cout << ans << std::endl;
  }

  return 0;
}