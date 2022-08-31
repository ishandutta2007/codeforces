#include <iostream>
#include <vector>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> adj(n, -1);
    std::vector<int> vis(n, 0);

    for(int i = 0; i < m; i++) {
      int x, y;
      std::cin >> x >> y;
      x--; y--;
      if(x != y)
        adj[x] = y;
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
      if((!vis[i]) && adj[i] != -1) {
        int c = 0;
        int u = i;
        vis[u] = i+1;
        while(true) {
          c++;
          u = adj[u];
          if(u == -1) {
            ans += c-1;
            break;
          }
          else if(vis[u]) {
            ans += c+(vis[u] == i+1);
            break;
          }
          else
            vis[u] = i+1;
        }
      }
    }

    std::cout << ans << std::endl;
  }

  return 0;
}