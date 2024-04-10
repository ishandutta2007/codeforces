#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, m, k;
    std::cin >> n >> m >> k;

    int max_n = 0, max_m = 0;
    int high_n = 0, high_m = 0;
    for(int i = 0; i < k; i++) {
      int x;
      std::cin >> x;
      if((x/m) >= 2) {
        max_n += x/m;
        high_n = std::max(high_n, x/m);
      }
      if((x/n) >= 2) {
        max_m += x/n;
        high_m = std::max(high_m, x/n);
      }
    }

    std::cout << ((max_n >= n && (n%2 == 0 || high_n > 2)) || (max_m >= m && (m%2 == 0 || high_m > 2))? "Yes" : "No") << std::endl;
  }

  return 0;
}