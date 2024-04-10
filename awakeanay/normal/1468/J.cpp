#include <iostream>
#include <vector>
#include <algorithm>

#define int long long 

int root(int u, int par[]) {
  if(par[u] < 0)
    return  u;
  return par[u] = root(par[u], par);
}

void merge(int u, int v, int par[]) {
  u = root(u, par);
  v = root(v, par);

  if(u == v)
    return;

  if(par[u] > par[v])
    u ^= v ^= u ^= v;

  par[u] += par[v];
  par[v] = u;
}

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, m, k;
    std::cin >> n >> m >> k;

    int par[n];
    for(int i = 0; i < n; i++)
      par[i] = -1;
    
    int minD = k;
    int minT = 0;
    std::vector<std::pair<int, std::pair<int, int> > > edgeL;
    for(int i = 0; i < m; i++) {
      int u, v, w;
      std::cin >> u >> v >> w;
      u--; v--;
      minD = std::min(minD, (w > k) ? w-k : k-w);
      edgeL.push_back({std::max(w-k, 0ll), {u, v}});
    }

    std::sort(edgeL.begin(), edgeL.end());

    for(int i = 0; i < m; i++) {
      if(root(edgeL[i].second.first, par) == root(edgeL[i].second.second, par))
        continue;

      merge(edgeL[i].second.first, edgeL[i].second.second, par);
      minT += edgeL[i].first;
    }

    std::cout << std::max(minD, minT) << std::endl;
  }

  return 0;
}