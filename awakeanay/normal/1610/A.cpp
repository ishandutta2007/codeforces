#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, m;
    std::cin >> n >> m;

    if(n == 1 && m == 1)
      std::cout << 0 << std::endl;
    else if(n == 1 || m == 1)
      std::cout << 1 << std::endl;
    else
      std::cout << 2 << std::endl;
  }

  return 0;
}