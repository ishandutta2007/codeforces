#include <iostream>
#include <algorithm>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, k;
    std::cin >> n >> k;

    int x[n];
    for(int i = 0; i < n; i++)
      std::cin >> x[i];

    for(int i = 0; i < n; i++) {
      int tmp;
      std::cin >> tmp;
    }

    std::sort(x, x+n);

    int left[n];
    int right[n];


    int ans = 0;
    for(int i = 0; i < n; i++) {
      left[i] = i+1-(std::lower_bound(x, x+n, x[i]-k)-x);
      ans = std::max(ans, left[i]);
    }

    for(int i = n-1; i >= 0; i--) {
      right[i] = (std::upper_bound(x, x+n, x[i]+k)-x)-i;
    }

    for(int i = 1; i < n; i++) {
      left[i] = std::max(left[i-1], left[i]);
      right[n-i-1] = std::max(right[n-1-i], right[n-i]);
    }

    for(int i = 0; i+1 < n; i++)
      ans = std::max(ans, left[i] + right[i+1]);

    std::cout << ans << std::endl;
  }

  return 0;
}