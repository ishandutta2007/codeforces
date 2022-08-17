#include <iostream>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, m;
    std::cin >> n >> m;

    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      m -= x;
    }

    if(m == 0)
      std::cout << "YES" << std::endl;
    else
      std::cout << "NO" << std::endl;
  }

  return 0;
}