#include <iostream>

#define int long long

signed main() {
  int t;
  t = 1;

  while(t--) {
    int h, n;
    std::cin >> h >> n;

    int a[n];
    int cur = 0;
    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
      a[i] = -a[i];
      cur += a[i];
      if(i) a[i] = std::max(cur, a[i-1]);
    }

    int m = 1;
    
    for(int i = 0; i < m; i++) {
      int x;
      x = h;

      int l = 0, r = n-1;
      while(l < r) {
        int mid = (l+r)/2;
        if(a[mid] >= x)
          r = mid;
        else
          l = mid+1;
      }

      if(a[l] >= x) {
        std::cout << l+1 << " ";
        continue;
      }

      if(cur <= 0) {
        std::cout << -1 << " ";
        continue;
      }

      l = 0; r = x/cur + 1;
      while(l < r) {
        int m = (l+r)/2;
        bool check = a[n-1] >= x-cur*m;
        if(check)
          r = m;
        else
          l = m+1;
      }
      int type = l;

      l = 0, r = n-1;
      while(l < r) {
        int mid = (l+r)/2;
        if(a[mid] >= x-type*cur)
          r = mid;
        else
          l = mid+1;
      }

      std::cout << type*n + l+1 << " ";
    }

    std::cout << std::endl;
  }

  return 0;
}