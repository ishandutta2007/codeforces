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

    int a[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    int ans = 0;
    for(int i = 1; i < n; i++) {
      int cur = 0;
      int r = n-1;
      while(r >= i) {
        if(a[r] == a[i-1]) {
          cur += r-i+1;
          break;
        }

        cur++;

        int lo = i, hi = r;
        while(lo < hi) {
          int mid = (lo+hi)/2;

          if(2*(a[mid]-a[i-1]) > (a[r]-a[i-1]))
            hi = mid;
          else
            lo = mid+1;
        }
        r = lo-1;
      }

      ans = std::max(ans, cur+1);
    }
    
    std::cout << n-ans << std::endl;

  }

  
  return 0;
}