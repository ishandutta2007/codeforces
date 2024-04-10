#include <iostream>
#include <algorithm>
#include <vector>

#define MAXN 200005

#define int long long

int par[MAXN];

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
  par[v] = u;
}

signed main() {
  int n, m;
  std::cin >> m >> n;

  int a[m], b[n];
  for(int i = 0; i < m; i++) {
    std::cin >> a[i];
    par[i] = -1;
  }

  for(int i = 0; i < n; i++) {
    std::cin >> b[i];
    par[i+m] = -1;
  }

  int ans = 0;
  std::vector<std::pair<int, std::pair<int, int> > > help;

  for(int i = 0; i < m; i++) {
    int k;
    std::cin >> k;
    for(int j = 0; j < k; j++) {
      int x;
      std::cin >> x;
      x--;
      help.push_back({a[i] + b[x], {i, x}});
    }
  }

  std::sort(help.begin(), help.end());
  std::reverse(help.begin(), help.end());

  for(int i = 0; i < help.size(); i++) {
    int u = help[i].second.first;
    int v = m+help[i].second.second;

    if(root(u) == root(v))
      ans += a[u] + b[v-m];

    merge(u, v);
  }

  std::cout << ans << std::endl;
}