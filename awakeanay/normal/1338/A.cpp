#include <iostream>

#define int long long 

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;
    
    int a[n];
    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
    }

    int max = a[0];
    int ans = 0;
    for(int i = 0; i < n; i++) {
      max = std::max(max, a[i]);
      int diff = max - a[i];

      int b = 0;
      while((1ll << b) <= diff)
        b++;

      ans = std::max(ans, b);
    }

    std::cout << ans << std::endl;
  }
}