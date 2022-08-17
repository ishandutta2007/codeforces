#include <iostream>
#include <vector>

#define int long long

const int MAXN = 200005;

int type[MAXN];
std::vector<int> Adj[MAXN];
int leaves, buds;

void dfs(int u, int p) {
  int count = 0;
  for(int j : Adj[u]) {
    if(j == p)
      continue;
    dfs(j, u);
    count += type[j] == 0;
  }

  if(count)
    type[u] = 1;
  else
    type[u] = 0;
  if(p != -1) {
    if(type[u])
      buds++;
    else
      leaves++;
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

    leaves = buds = 0;
    dfs(0, -1);

    int extra = 1;
    for(int j : Adj[0])
      if(type[j] == 0)
        extra = 0;

    std::cout << leaves-buds+extra << std::endl;
  }

  return 0;
}