#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, z;
    std::cin >> n >> z;

    int ans = 0;
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      ans = std::max(ans, z|x);
    }

    std::cout << ans << std::endl;
  }

  return 0;
}