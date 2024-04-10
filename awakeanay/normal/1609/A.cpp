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
    
    int a[n];
    int max = 1;

    int ans = 0;
    int p2 = 1;
    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
      while(a[i]%2 == 0) {
        p2 *= 2;;
        a[i] /= 2;
      }
      max = std::max(max, a[i]);
      ans += a[i];
    }

    ans -= max;
    ans += max*p2;

    std::cout << ans << std::endl;
  }

  return 0;
}