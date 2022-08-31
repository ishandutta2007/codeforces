#include <iostream>
#include <algorithm>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, m;
    std::cin >> n >> m;

    int b[m];
    int a[m];
    for(int i = 0; i < m; i++) {
      std::cin >> a[i];
    }
    std::sort(a, a+m);

    for(int i = 0; i < m; i++) {
      b[i] = (a[i] - a[(i-1+m)%m] + n - 1)%n;
    }

    std::sort(b, b+m);
    std::reverse(b, b+m);

    int cur = 0;
    int ans = 0;
    for(int i = 0; i < m; i++) {
      int val = b[i] - 2*cur;
      if(val <= 0)
        continue;
      if(val <= 2) {
        cur++;
        ans++;
      }
      else {
        cur += 2;
        ans += val-1;
      }
    }

    std::cout << n-ans << std::endl;
  }

  return 0;
}