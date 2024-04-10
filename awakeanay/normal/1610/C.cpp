#include <iostream>
#include <set>

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
      std::cin >> a[i] >> b[i];
    }

    int lo = 1, hi = n+1;
    while(lo < hi) {
      int mid = (lo+hi)/2;
      int cur = 0;
      for(int i = 0; i < n; i++) {
        if(b[i] >= cur && a[i]+cur+1 >= mid)
          cur++;
      }

      if(cur < mid)
        hi = mid;
      else
        lo = mid+1;
    }

    std::cout << lo-1 << std::endl;
  }

  return 0;
}