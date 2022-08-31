#include <iostream>

#define int long long

int gcd(int a, int b) {
  if(a == 0)
    return b;
  return gcd(b%a, a);
}

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int x = 0;
    int n, k;
    std::cin >> n >> k;

    int a;
    std::cin >> a;
    for(int i = 1; i < n; i++) {
      int y;
      std::cin >> y;
      x = gcd(x, y < a ? a-y : y-a);
    }

    int che = k > a ? k-a : a-k;
    if(x == 0) {
      if(k == a)
        std::cout << "YES" << std::endl;
      else
        std::cout << "NO" << std::endl;
    }
    else if(che%x == 0)
      std::cout << "YES" << std::endl;
    else
      std::cout << "NO" << std::endl;
  }

  return 0;
}