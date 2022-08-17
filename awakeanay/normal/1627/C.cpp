#include <iostream>
#include <vector>

#define int long long

const int MAXN = 100005;

std::vector<std::pair<int, int> > Adj[MAXN];

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::vector<int> deg(n, 0);
    for(int i = 0; i < n; i++)
      Adj[i].clear();
    for(int i = 0; i+1 < n; i++) {
      int u, v;
      std::cin >> u >> v;
      u--; v--;
      Adj[u].push_back({v, i});
      Adj[v].push_back({u, i});
      deg[u]++;
      deg[v]++;
    }

    int root = -1;
    int imposs = 0;
    for(int i = 0; i < n; i++) {
      if(deg[i] == 1)
        root = i;
      if(deg[i] > 2)
        imposs = 1;
    }

    if(imposs) {
      std::cout << -1 << std::endl;
      continue;
    }

    int cur = 3;
    int p = -1;
    int u = root;
    int ans[n-1];
    for(int i = 1; i < n; i++) {
      for(auto j : Adj[u]) {
        if(j.first != p) {
          p = u;
          ans[j.second] = cur;
          u = j.first;
          cur = 5-cur;
          break;
        }
      }
    }

    for(int i = 0; i+1 < n; i++)
      std::cout << ans[i] << " ";
    std::cout << std::endl;
  }

  return 0;
}