#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, k;
    std::cin >> n >> k;

    int a[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    if(k == 1) {
      std::cout << (n-1)/2 << std::endl;
    }
    else {
      int ans = 0;
      for(int i = 1; i+1 < n; i++)
        ans += a[i] > a[i-1] + a[i+1];
      std::cout << ans << std::endl;
    }
  }

  return 0;
}