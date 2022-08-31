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

    int ans = ~0;
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      if(i != x)
        ans &= x;
    }

    std::cout << ans << std::endl;
  }

  return 0;
}