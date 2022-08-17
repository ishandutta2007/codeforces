#include <iostream>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, m, x;
    std::cin >> n >> m >> x;

    x--;

    int a = x%n, b = x/n;
    int k = a*m + b;
    std::cout << k+1 << std::endl;
  }

  return 0;
}