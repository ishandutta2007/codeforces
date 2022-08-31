#include <iostream>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, x;
    std::cin >> n >> x;

    int a[n];
    int sum = 0;
    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
      sum += a[i];
    }

    if(sum == x) {
      std::cout << "NO" << std::endl;
      continue;
    }

    std::cout << "YES" << std::endl;
    int cur = 0;
    for(int i = 0; i < n; i++) {
      cur += a[i];
      if(cur == x) {
        a[i] ^= a[i+1] ^= a[i] ^= a[i+1];
        break;
      }
    }

    for(int i = 0; i < n; i++)
      std::cout << a[i] << " ";
    std::cout << std::endl;
  }

  return 0;
}