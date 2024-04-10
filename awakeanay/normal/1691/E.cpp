#include <iostream>
#include <algorithm>
#include <set>

#define int long long

const int MAXN = 100005;

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
    int n;
    std::cin >> n;

    std::pair<int, int> list[2*n];
    int l[n], r[n], c[n];
    for(int i = 0; i < n; i++) {
      par[i] = -1;
      std::cin >> c[i] >> l[i] >> r[i];
      list[2*i] = {l[i], -i-1};
      list[2*i+1] = {r[i], n-i};
    }

    std::sort(list, list+2*n);

    std::set<int> type[2];
    for(int i = 0; i < 2*n; i++) {
      if(list[i].second > 0) {
        int u = n-list[i].second;
        int tc = c[u]^1;
        
        if(!type[tc].empty()) {
          std::pair<int, int> max = {-1, -1};
          for(int j : type[tc]) {
            max = std::max(max, {r[j], j});
            merge(u, j);
          }
          type[tc].clear();
          type[tc].insert(max.second);
        }

        type[tc^1].erase(u);
      }
      else {
        int u = -list[i].second-1;
        type[c[u]].insert(u);
      }
    }

    int ans = 0;
    for(int i = 0; i < n; i++)
      ans += par[i] < 0;
    std::cout << ans << std::endl;
  }

  return 0;
}