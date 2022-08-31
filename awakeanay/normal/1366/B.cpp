#include <iostream>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, m, x;
    std::cin >> n >> x >> m;

    int l = x, r = x;
    for(int i = 0; i < m; i++) {
      int a, b;
      std::cin >> a >> b;

      if(b < l)
        continue;

      if(a > r)
        continue;

      l = std::min(l, a);
      r = std::max(r, b);
    }

    std::cout << r-l+1 << std::endl;
  }

  return 0;
}