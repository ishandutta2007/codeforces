#include <iostream>
#include <vector>

#define int long long

const int MAXN = 200005;

std::vector<int> Adj[MAXN];
int stime[MAXN], etime[MAXN];
int depth[MAXN];
int par[MAXN];
int counter = -1;

void dfs(int u, int p, int d) {
  par[u] = p;
  stime[u] = ++counter;
  depth[u] = d;
  for(int j : Adj[u]) {
    if(j == p)
      continue;
    dfs(j, u, d+1);
  }
  etime[u] = counter;
}

signed main() {
  int n, m;
  std::cin >> n >> m; 

  for(int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    u--; v--;
    Adj[u].push_back(v);
    Adj[v].push_back(u);
  }
  dfs(0, -1, 0);

  for(int i = 0; i < m; i++) {
    bool poss = true;
    int k;
    std::cin >> k;

    std::vector<int> query;
    int md = -1;
    int check = -1;
    for(int j = 0; j < k; j++) {
      int x;
      std::cin >> x;
      query.push_back(x-1);
      x--;
      if(depth[x] > md) {
        md = depth[x];
        check = x;
      }
    }

    for(int j = 0; j < k; j++) {
      if(query[j] == 0)
        continue;
      int y = par[query[j]];
      if(stime[check] < stime[y] || stime[check] > etime[y])
        poss = false;
    }


    if(poss)
      std::cout << "YES" << std::endl;
    else
      std::cout << "NO" << std::endl;
  }

  return 0;
}