/*
Author: AwakeAnay
Date: 17/02/2020
Time: 21:11:42
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, x;
    std::cin >> n >> x;

    std::vector<int> a(n);
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    std::sort(a.begin(), a.end());
    int ans = 1000000000000;
    for(int i = 0; i < n; i++) {
      if(a[i] == x) {
        ans = 1;
      }
    }

    if(a[n-1] > x)
      ans = std::min(ans, 2ll);
    else
      ans = std::min(ans, x/a[n-1] + (x%a[n-1] != 0));

    std::cout << ans << std::endl;
  }

  return 0;
}