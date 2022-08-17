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

    int a;
    for(int i = 0; i < n; i++)
      std::cin >> a;

    std::cout << 3*n << std::endl;
    for(int i = 0; i < n; i+=2) {
      int x = i+1;
      int y = i+2;
      std::cout << 2 << " " << x << " " << y << std::endl;
      std::cout << 1 << " " << x << " " << y << std::endl;
      std::cout << 2 << " " << x << " " << y << std::endl;
      std::cout << 1 << " " << x << " " << y << std::endl;
      std::cout << 2 << " " << x << " " << y << std::endl;
      std::cout << 1 << " " << x << " " << y << std::endl;
    }
  }

  return 0;
}