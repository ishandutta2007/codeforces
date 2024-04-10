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

    int sum = 0;
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      sum += x;
    }

    if(sum == n)
      std::cout << 0 << std::endl;
    else if(sum < n)
      std::cout << 1 << std::endl;
    else if(sum > n)
      std::cout << sum-n << std::endl;
  }

  return 0;
}