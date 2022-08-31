#include <iostream>
#include <set>
#include <vector>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::vector<int> Adj[n];
    std::vector<int> d(n, 0), deg(n, 0);
    std::set<std::pair<int, int> > dij;

    for(int i = 0; i < n; i++) {
      int k;
      std::cin >> k;
      deg[i] = k;

      for(int j = 0; j < k; j++) {
        int x;
        std::cin >> x;
        x--;
        Adj[x].push_back(i);
      }

      if(k == 0) {
        d[i] = 1;
        dij.insert({d[i], i});
      }
    }

    int count = 0;
    int ans = 0;
    while(!dij.empty()) {
      int u = (*dij.begin()).second;
      dij.erase(dij.begin());
      count++;
      ans = std::max(ans, d[u]);

      for(int j : Adj[u]) {
        deg[j]--;
        int add = j < u;
        d[j] = std::max(d[j], d[u] + add);
        if(deg[j] == 0) {
          dij.insert({d[j], j});
        }
      }
    }

    if(count != n) {
      std::cout << -1 << std::endl;
    }
    else
      std::cout << ans << std::endl;
  }

  return 0;
}