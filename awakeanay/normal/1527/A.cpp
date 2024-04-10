#include <iostream>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int ans = n;
    for(int i = 0; i < 35; i++) {
      if((n >> i)&1) {
        int k = n%(1ll << (i+1));
        k -= (1ll << i);
        ans = std::min(ans, n-k-1);
      }
    }

    std::cout << ans << std::endl;
  }

  return 0;
}