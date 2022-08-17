#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t; 

  while(t--) {
    int a, b, c;
    std::cin >> a >> b >> c;

    int x = a+b+c;
    int y = b+c;
    int z = c;

    std::cout << x << " " << y << " " << z << std::endl;
  }

  return 0;
}