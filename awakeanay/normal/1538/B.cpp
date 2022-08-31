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
    int a[n];
    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
      sum += a[i];
    }

    if(sum%n != 0) {
      std::cout << -1 << std::endl;
    }
    else {
      sum /= n;
      int ans = 0;
      for(int i = 0; i < n; i++)
        if(a[i] > sum)
          ans++;
      std::cout << ans << std::endl;
    }
  }

  return 0;
}