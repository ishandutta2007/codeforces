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

    if(a + b == c || b + c == a || a + c == b || (a == b && c%2 == 0) || (b == c && a%2 == 0) || (a == c && b%2 == 0))
      std::cout << "YES" << std::endl;
    else
      std::cout << "NO" << std::endl;
  }

  return 0;
}