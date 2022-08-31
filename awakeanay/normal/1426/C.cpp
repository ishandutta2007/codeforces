#include <iostream>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int ans = n;
    for(int i = 0; i*i <= n; i++) {
      ans = std::min(i + (n-i-1)/(i+1) + ((n-i-1)%(i+1) != 0), ans);
    }

    std::cout << ans << std::endl;
  }

  return 0;
}