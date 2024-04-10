#include <iostream>
#include <set>
#include <vector>

#define MAXN 200000

int inmax = 0, min = 0;
int n;
std::vector<int> Adj[MAXN];
std::set<int> s;
int leaves = 0;

int dfs1(int u, int p, int h) {
  if(Adj[u].size() == 1)
    return 1;

  int cur = 0;
  for(int j : Adj[u]) {
    if(j == p)
      continue;
    
    cur += dfs1(j, u, 1-h);
  }

  if(cur > 0)
    s.insert(h);

  leaves += cur;

  inmax += std::max(0, cur-1);
  return 0;
}

signed main() {
  std::cin >> n;
  
  int root;
  for(int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    u--; v--;
    Adj[u].push_back(v);
    Adj[v].push_back(u);

    if(Adj[u].size() > 1) root = u;
    if(Adj[v].size() > 1) root = v;
  }

  dfs1(root, -1, 0);

  std::cout << 2*s.size()-1 << " " << n-1-inmax << std::endl;
}