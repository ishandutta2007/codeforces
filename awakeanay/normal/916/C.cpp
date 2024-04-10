#include <iostream>

signed main() {
  int n, m;
  std::cin >> n >> m;

  int p = 274961;

  std::cout << p << " " << p << std::endl;
  for(int i = 1; i < n-1; i++) {
    std::cout << i << " " << i+1 << " " << 1 << std::endl;
  }

  std::cout << n-1 << " " << n << " " << p-(n-2) << std::endl;
  m -= n-1;
  for(int i = 1; i <= n && m; i++) {
    for(int j = i+2; j <= n && m; j++) {
      std::cout << i << " " << j << " " << 1000000 << std::endl;
      m--;
    }
  }

  return 0;
}