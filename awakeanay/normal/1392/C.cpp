#include <iostream>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int a[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    int ans = 0;
    for(int i = 0; i+1 < n; i++) {
      if(a[i] > a[i+1])
        ans += a[i] - a[i+1];
    }

    std::cout << ans << std::endl;
  }

  return 0;
}