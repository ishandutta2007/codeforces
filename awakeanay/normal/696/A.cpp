#include <iostream>
#include <map>

#define int long long

signed main() {
  int q;
  std::cin >> q;

  std::map<int, int> d;

  while(q--) {
    int t;
    std::cin >> t;

    if(t == 1) {
      int u, v, w;
      std::cin >> u >> v >> w;

      if(u < v)
        u ^= v ^= u ^= v;

      int x = 0, y = 0, z = u;
      while(z > 0) {
        x++;
        z >>= 1;
      }

      z = v;
      while(z > 0) {
        y++;
        z >>= 1;
      }
  
      while(x > y) {
        d[u] += w;
        x--;
        u >>= 1;
      }

      while(u != v) {
        d[u] += w;
        d[v] += w;
        u >>= 1;
        v >>= 1;
      }
    }
    else {
      int u, v;
      std::cin >> u >> v;
      
      int ans = 0;

      if(u < v)
        u ^= v ^= u ^= v;

      int x = 0, y = 0, z = u;
      while(z > 0) {
        x++;
        z >>= 1;
      }

      z = v;
      while(z > 0) {
        y++;
        z >>= 1;
      }

      while(x > y) {
        ans += d[u];
        u >>= 1;
        x--;
      }

      while(u != v) {
        ans += d[u];
        ans += d[v];
        u >>= 1;
        v >>= 1;
      }

      std::cout << ans << std::endl;
    }
  }

  return 0;
}