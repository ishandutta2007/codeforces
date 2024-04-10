#include <iostream>
#include <vector>

#define int long long

std::vector<int> inC;
int cur = 0;
std::vector<int> Adj[200001];
std::vector<int> color;
int pivot = -1;

int dfs(int u, int p) {
  color[u] = 1;
  for(int j : Adj[u]) {
    if(j == p)
      continue;
    if(color[j] == 1) {
      inC[u] = true;
      pivot = j;
      return 1;
    }
    int next = dfs(j, u);
    if(next == 1) {
      inC[u] = true;
      return 1 + (pivot == u);
    }
  }
  color[u] = 2;
  return 0;
}

void dfs2(int u, int p) {
  cur++;
  for(int j : Adj[u])
    if(j != p && (!inC[j]))
      dfs2(j, u);
}

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    for(int i = 0; i < n; i++)
      Adj[i].clear();
    inC = std::vector<int>(n, 0);
    color = inC;

    for(int i = 0; i < n; i++) {
      int u, v;
      std::cin >> u >> v;
      u--; v--;
      Adj[u].push_back(v);
      Adj[v].push_back(u);
    }

    dfs(0, -1);

    int ans = (n*(n-1))/2;
    int add = n*n;

    for(int i = 0; i < n; i++)
      if(inC[i]) {
        cur = 0;
        dfs2(i, -1);
        add -= cur*cur;
      }

    std::cout << ans + add/2 << std::endl;
  }

  return 0;
}