#include <iostream>
#include <vector>

#define int long long

int query(int x) {
  std::cout << "? " << x+1 << std::endl;
  int y;
  std::cin >> y;
  return y-1;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int p[n];
    std::vector<int> vis(n, 0);

    for(int i = 0; i < n; i++) {
      if(vis[i])
        continue;

      int u = query(i);
      int last = u;
      vis[u] = 1;
      while(true) {
        int v = query(i);
        vis[v] = 1;
        p[u] = v;
        u = v;
        if(u == last)
          break;
      }
    }

    std::cout << "! ";
    for(int i = 0; i < n; i++)
      std::cout << p[i]+1 << " ";
    std::cout << std::endl;
  }

  return 0;
}