#include <iostream>
#include <vector>

#define int long long

const int MAXN = 205;

std::vector<int> Adj[MAXN];
int vis[MAXN];
int d[MAXN][MAXN];
int d_cpy[MAXN][MAXN];
int nbip;

void dfs(int u, int c) {
  vis[u] = c;
  for(int j : Adj[u]) {
    if(vis[j] == c)
      nbip |= 1;
    if(!vis[j])
      dfs(j, 3-c);
  }
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      d[i][j] = i == j ? 0 : n+1;

  for(int i = 0; i < m; i++) {
    int u, v, w;
    std::cin >> u >> v >> w;
    u--; v--;
    d[u][v] = d[v][u] = 1;
    if(w)
      d[v][u] = -1;
    Adj[u].push_back(v);
    Adj[v].push_back(u);
  }

  dfs(0, 1);

  if(nbip) {
    std::cout << "NO" << std::endl;
    return 0;
  }

  bool poss = true;
  for(int i = 0; i < n && poss; i++) {
    for(int j = 0; j < n; j++) {
      for(int k = 0; k < n; k++)
        d[j][k] = std::min(d[j][k], d[j][i] + d[i][k]);
      if(d[j][j] < 0) {
        poss = false;
        break;
      }
    }
  }

  if(!poss) {
    std::cout << "NO" << std::endl;
    return 0;
  }

  std::cout << "YES" << std::endl;
  std::pair<int, int> best = {-1, -1};
  for(int i = 0; i < n; i++) {
    int max = -n, min = n;
    for(int j = 0; j < n; j++) {
      max = std::max(max, d[i][j]);
      min = std::min(min, d[i][j]);
    }
    best = std::max(best, {max-min, i});
  }
  std::cout << best.first << std::endl;
  for(int i = 0; i < n; i++)
    std::cout << d[best.second][i]+best.first << " ";
  std::cout << std::endl;

  return 0;
}