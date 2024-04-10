#include <iostream>

#define MAXN 200005

int par[MAXN];
int best[MAXN];

int root(int u) {
  if(par[u] < 0)
    return u;

  return par[u] = root(par[u]);
}

void merge(int u, int v) {
  u = root(u); v = root(v);
  if(u == v)
    return;

  if(par[u] > par[v])
    u ^= v ^= u ^= v;

  par[u] += par[v];
  best[u] = std::max(best[u], best[v]);
  par[v] = u;
}

signed main() {
  int n, m;
  std::cin >> n >> m;

  for(int i = 0; i < n; i++) {
    par[i] = -1;
    best[i] = i;
  }

  for(int i = 0; i < m; i++) {
    int u, v;
    std::cin >> u >> v;
    u--; v--;
    merge(u, v);
  }

  int ans = 0;
  for(int i = 0; i+1 < n; i++) {
    if(best[root(i)] > i && root(i) != root(i+1)) {
      ans++;
      merge(i, i+1);
    }
  }

  std::cout << ans << std::endl;

  return 0;
}