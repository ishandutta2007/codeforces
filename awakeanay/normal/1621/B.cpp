#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n; 

    int min = 10000000000, max = 0;
    int bmin = 0, bmax = 0;
    int full = -1;

    for(int i = 0; i < n; i++) {
      int l, r, c;
      std::cin >> l >> r >> c;

      if(l < min) {
        min = l;
        full = -1;
        bmin = c;
      }
      else if(l == min)
        bmin = std::min(bmin, c);

      if(r > max) {
        max = r;
        full = -1;
        bmax = c;
      }
      else if(r == max)
        bmax = std::min(bmax, c);

      if(l == min && r == max) {
        if(full == -1 || full > c)
          full = c;
      }

      int cur = bmin + bmax;
      if(full != -1)
        cur = std::min(cur, full);
      
      std::cout << cur << std::endl;
    }
  }

  return 0;
}