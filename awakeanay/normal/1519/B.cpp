#include <iostream>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, m, k;
    std::cin >> n >> m >> k;

    if(n*m == k+1)
      std::cout << "YES" << std::endl;
    else
      std::cout << "NO" << std::endl;
  }

  return 0;
}