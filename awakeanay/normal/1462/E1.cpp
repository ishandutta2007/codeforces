#include <iostream>
#include <algorithm>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, m, k;
    std::cin >> n;

    k = 2; m = 3;

    int a[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    std::sort(a, a+n);

    int l = 0;
    int ans = 0;
    for(int i = 0; i < n; i++) {
      while(a[i] - a[l] > k)
        l++;

      if(i-l < m-1)
        continue;

      ans += ((i-l)*(i-l-1))/2;

    }

    std::cout << ans << std::endl;
  }

  return 0;
}