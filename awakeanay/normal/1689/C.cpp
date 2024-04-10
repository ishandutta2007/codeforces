#include <iostream>
#include <vector>

#define int long long

const int MAXN = 300005;

std::vector<int> Adj[MAXN];
int sub[MAXN];

int dfs(int u, int p) {
  sub[u] = 1;
  std::vector<int> next;
  std::vector<int> child;
  for(int j : Adj[u]) {
    if(j == p)
      continue;
    next.push_back(dfs(j, u));
    sub[u] += sub[j];
    child.push_back(sub[j]);
  }
  if(next.size() == 0) {
    return 0;
  }
  else if(next.size() == 1) {
    return sub[u]-2;
  }
  else {
    return std::max(child[0] - 1 + next[1], child[1] - 1 + next[0]);
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

    for(int i = 0; i < n; i++)
      Adj[i].clear();

    for(int i = 1; i < n; i++) {
      int u, v;
      std::cin >> u >> v;
      u--; v--;
      Adj[u].push_back(v);
      Adj[v].push_back(u);
    }

    std::cout << dfs(0, -1) << std::endl;
  }

  return 0;
}