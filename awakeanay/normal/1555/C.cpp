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

    int a[n], b[n];
    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
      if(i)
        a[i] += a[i-1];
    }
    for(int i = 0; i < n; i++) {
      std::cin >> b[i];
      if(i)
        b[i] += b[i-1];
    }

    int ans = b[n-1];
    for(int i = 0; i < n; i++) {
      int cur = 0;
      if(i)
        cur += b[i-1];
      cur = std::max(cur, a[n-1]-a[i]);

      ans = std::min(cur, ans);
    }

    std::cout << ans << std::endl;
  }

  return 0;
}