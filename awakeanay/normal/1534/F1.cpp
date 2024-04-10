#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

#define int long long

using namespace std;

// NOTE: Code for SCC has been copied from https://cp-algorithms.com/graph/strongly-connected-components.html
// Start of copied code
vector<vector<int> > adj, adj_rev;
vector<int> used;
vector<int> order, component;

void dfs1(int v) {
  used[v] = true;

  for (auto u : adj[v])
    if (!used[u])
      dfs1(u);

  order.push_back(v);
}

void dfs2(int v) {
    used[v] = true;
    component.push_back(v);

    for (auto u : adj_rev[v])
        if (!used[u])
            dfs2(u);
}
// End of copied code

void addE(int u, int v) {
  adj[u].push_back(v);
  adj_rev[v].push_back(u);
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;

  int cfree = 0;
  int id[n][m];
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      char c;
      std::cin >> c;
      if(c == '#')
        id[i][j] = cfree++;
      else
        id[i][j] = -1;
    }
  }

  if(cfree == 0) {
    std::cout << 0 << std::endl;
    return 0;
  }

  int firstB[n][m];
  for(int i = 0; i < m; i++) {
    int last = -1;
    for(int j = n-1; j >= 0; j--) {
      firstB[j][i] = last;
      if(id[j][i] != -1)
        last = j;
    }
  }

  adj = adj_rev = std::vector<std::vector<int> >(cfree);

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(id[i][j] == -1)
        continue;
      if(firstB[i][j] != -1) {
        addE(id[i][j], id[firstB[i][j]][j]);
      }
      if(j+1 < m) {
        int y = firstB[i][j+1];
        if(id[i][j+1] != -1)
          y = i;
        if(j+1 < m && y != -1) {
          addE(id[i][j], id[y][j+1]);
        }
      }
      if(j-1 >= 0) {
        int y = firstB[i][j-1];
        if(id[i][j-1] != -1)
          y = i;
        if(j-1 >= 0 && y != -1) {
          addE(id[i][j], id[y][j-1]);
        }
      }
      if(i && id[i-1][j] != -1)
        addE(id[i][j], id[i-1][j]);
    }
  }

  used = std::vector<int>(cfree, 0);

  for(int i = 0; i < cfree; i++)
    if(!used[i])
      dfs1(i);

  used = std::vector<int>(cfree, 0);
  std::reverse(order.begin(), order.end());

  std::set<int> roots;
  std::vector<int> par(cfree, 0);

  for(int u : order) {
    if(used[u])
      continue;

    dfs2(u);
    int cr = component.front();
    for(int v : component)
      par[v] = cr;
    roots.insert(cr);

    component.clear();
  }

  for(int i = 0; i < cfree; i++) {
    for(int j : adj[i]) {
      if(par[j] != par[i])
        roots.erase(par[j]);
    }
  }

  std::cout << roots.size() << std::endl;

  return 0;
}