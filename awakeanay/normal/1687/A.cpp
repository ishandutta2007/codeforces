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

    int a[n+1];
    a[0] = 0;
    int init = std::min(n, k);
    int max = 0;
    for(int i = 1; i <= n; i++) {
      std::cin >> a[i];
      a[i] += a[i-1];
      if(i-init >= 0)
        max = std::max(max, a[i] - a[i-init]);
    }

    if(n == 1) {
      std::cout << k + a[1] - 1 << std::endl;
      continue;
    }
    else if(k <= n) {
      max += (init*(init-1))/2;
      std::cout << max << std::endl;
      continue;
    }

    int cur = max + n*k - ((n*(n+1))/2);

    std::cout << cur << std::endl;
  }

  return 0;
}