#include <iostream>
#include <vector>

#define int long long

const int MAXN = 300005;

std::vector<std::pair<int, int> > Adj[MAXN];
int node[MAXN];
int edge[MAXN];

int ct = 0;
int n;

void dfs(int u, int p, int d) {
  int val = ct++;
  node[u] = d*n + val;
  
  for(auto j : Adj[u]) {
    if(j.first == p) {
      edge[j.second] = (d^1)*n + val;
    }
    else {
      dfs(j.first, u, d^1);
    }
  }
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;
  
  while(t--) {
    int p;
    std::cin >> p;

    n = 1 << p;

    for(int i = 0; i < n; i++)
      Adj[i].clear();

    for(int i = 0; i+1 < n; i++) {
      int u, v;
      std::cin >> u >> v;
      u--; v--;
      Adj[u].push_back({v, i});
      Adj[v].push_back({u, i});
    }

    ct = 0;
    dfs(0, -1, 1);
    std::cout << 1 << std::endl;

    for(int i = 0; i < n; i++)
      std::cout << node[i] << " ";
    std::cout << std::endl;
    for(int i = 0; i+1 < n; i++)
      std::cout << edge[i] << " ";
    std::cout << std::endl;
  }

  return 0;
}