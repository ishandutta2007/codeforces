#include <iostream>
#include <vector>

#define int long long

const int MAXN = 100005;

std::vector<int> Adj[MAXN];
int sz[MAXN];
int pt[MAXN];
int leaf, par;

void dfs(int u, int p) {
  sz[u] = 1;
  pt[u] = p;
  for(int j : Adj[u]) {
    if(j == p)
      continue;
    dfs(j, u);
    sz[u] += sz[j];
  }

  if(sz[u] == 1) {
    leaf = u;
    par = p;
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

    int x, y;
    for(int i = 1; i < n; i++) {
      int u, v;
      std::cin >> u >> v;
      x = u;
      y = v;
      u--; v--;
      Adj[u].push_back(v);
      Adj[v].push_back(u);
    }

    dfs(0, -1);
    int done = -1;

    for(int i = 0; i < n; i++) {
      if(2*sz[i] == n) {
        done = i;
        dfs(i, pt[i]);
      }
    }

    if(done == -1) {
      std::cout << x << " " << y << std::endl;
      std::cout << x << " " << y << std::endl;
    }
    else {
      std::cout << leaf+1 << " " << par+1 << std::endl;
      std::cout << pt[done]+1 << " " << leaf+1 << std::endl;
    }
  }

  return 0;
}