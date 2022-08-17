#include <iostream>
#include <algorithm>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;

  int a[n];
  int sum = 0;
  for(int i = 0; i < n; i++) {
    std::cin >> a[i];
    sum += a[i];
  }

  if(sum < m) {
    std::cout << -1 << std::endl;
    return 0;
  }

  std::sort(a, a+n);
  std::reverse(a, a+n);

  int b[n];
  for(int i = 0; i < n; i++) {
    b[i] = a[i];
    if(i)
      b[i] += b[i-1];
  }

  int q = 1;
  while(q--) {
    //std::cin >> m;

    if(sum < m) {
      std::cout << -1 << std::endl;
      continue;
    }

    int lo = 1, hi = n;
    while(lo < hi) {
      int mid = (lo+hi)/2;

      int l = 0, r = n;
      while(l < r) {
        int m = (l+r)/2;
        if(a[m] <= m/mid)
          r = m;
        else
          l = m+1;
      }

      int cur = b[l-1];
      r = l-l%mid;
      r--;
      r /= mid;

      cur -= ((r*(r+1))/2)*mid;
      cur -= (l%mid)*((l-1)/mid);

      if(cur >= m)
        hi = mid;
      else
        lo = mid+1;
    }

    std::cout << lo << std::endl;
  }

  /*
  int ans = n;
  for(int i = 1; i <= n; i++) {
    int cur = 0;
    int add = 0;
    for(int j = 0; j < n; j++) {
      add += a[j];
      add -= cur/i;
      if(add >= m)
        ans = std::min(ans, i);
      cur++;
    }
  }

  std::cout << ans << std::endl;
  */

  return 0;
}