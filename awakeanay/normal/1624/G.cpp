#include <iostream>

#define int long long

const int LOG = 32;
const int MAXN = 200005;

int par[MAXN];

int root(int u) {
  if(par[u] < 0)
    return u;
  return par[u] = root(par[u]);
}

void merge(int u, int v) {
  u = root(u);
  v = root(v);

  if(u == v)
    return;

  if(par[u] > par[v])
    u ^= v ^= u ^= v;

  par[u] += par[v];
  par[v] = u;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, m;
    std::cin >> n >> m;

    std::pair<std::pair<int, int>, int> edges[m];
    for(int i = 0; i < m; i++) {
      int u, v, w;
      std::cin >> u >> v >> w;
      u--; v--;
      edges[i] = {{u, v}, w};
    }

    int cur = 0;
    int mk = (1ll << LOG) - 1ll;
    for(int i = LOG-1; i >= 0; i--) {
      int test = cur | (1ll << i);
      for(int j = 0; j < n; j++)
        par[j] = -1;

      for(int j = 0; j < m; j++) {
        if((edges[j].second&test) == 0) {
          merge(edges[j].first.first, edges[j].first.second);
        }
      }

      if(par[root(0)] == -n)
        cur = test;
    }

    std::cout << (mk^cur) << std::endl;
  }

  return 0;
}