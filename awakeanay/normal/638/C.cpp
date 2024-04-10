#include <iostream>
#include <vector>

#define int long long

const int MAXN = 200005;

std::vector<std::pair<int, int> > Adj[MAXN];
int deg[MAXN];
std::vector<int> ans[MAXN];

void dfs(int u, int p, int c) {
  int cur = 0;
  for(auto j : Adj[u]) {
    if(j.first == p)
      continue;
    if(cur == c)
      cur++;
    ans[cur].push_back(j.second);
    dfs(j.first, u, cur);
    cur++;
  }
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  int max = 0;
  for(int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    u--; v--;

    Adj[u].push_back({v, i});
    Adj[v].push_back({u, i});

    deg[u]++;
    deg[v]++;

    if(deg[u] > deg[max])
      max = u;
    if(deg[v] > deg[max])
      max = v;
  }

  dfs(max, -1, -1);

  std::cout << deg[max] << std::endl;
  for(int i = 0; i < deg[max]; i++) {
    std::cout << ans[i].size() << " ";
    for(int j : ans[i])
      std::cout << j << " ";
    std::cout << std::endl;
  }

  return 0;
}