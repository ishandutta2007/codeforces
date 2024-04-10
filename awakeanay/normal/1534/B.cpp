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

    int a[n+2];
    a[0] = a[n+1] = 0;
    for(int i = 1; i <= n; i++)
      std::cin >> a[i];

    int ans = 0;
    for(int i = 1; i <= n; i++) {
      int down = std::max(a[i-1], a[i+1]);
      if(a[i] > down) {
        ans += a[i]-down;
        a[i] = down;
      }
      ans += a[i] > a[i-1] ? a[i]-a[i-1] : a[i-1]-a[i];
    }

    ans += a[n];
    std::cout << ans << std::endl;
  }

  return 0;
}