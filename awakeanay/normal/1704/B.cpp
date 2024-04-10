#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, x;
    std::cin >> n >> x;

    int a[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    int tot = -1;
    int cur = 0;
    while(cur < n) {
      tot++;
      int min = a[cur];
      int max = a[cur];
      cur++;
      while(cur < n) {
        max = std::max(max, a[cur]);
        min = std::min(min, a[cur]);
        if(max-min > 2*x)
          break;
        cur++;
      }
    }

    std::cout << tot << std::endl;
  }

  return 0;
}