#include <iostream>
#include <vector>
#include <algorithm>

#define int long long

const int MAXN = 100005;

int par[MAXN], p2[MAXN];

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
  p2[u] += p2[v];
  par[v] = u;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, m, k;
  std::cin >> n >> m >> k;

  for(int i = 0; i < n; i++) {
    par[i] = -1;
    p2[i] = 0;
  }

  for(int i = 0; i < k; i++) {
    int x;
    std::cin >> x;
    x--;
    p2[x]++;
  }

  std::vector<std::pair<int, std::pair<int, int> > > list;
  for(int i = 0; i < m; i++) {
    int u, v, w;
    std::cin >> u >> v >> w;
    u--; v--;

    list.push_back({w, {u, v}});
  }

  std::sort(list.begin(), list.end());

  int ans = 0;
  for(int i = 0; i < m; i++) {
    int u = list[i].second.first;
    int v = list[i].second.second;
    int w = list[i].first;

    ans = w;
    merge(u, v);
    int x = root(u);

    if(p2[x] == k)
      break;
  }

  for(int i = 0; i < k; i++) {
    std::cout << ans << " ";
  }

  std::cout << std::endl;

  return 0;
}