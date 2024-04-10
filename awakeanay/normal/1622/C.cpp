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

    int a[n];
    int pref[n];
    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
    }

    std::sort(a, a+n);

    for(int i = 0; i < n; i++) {
      pref[i] = a[i];
      if(i)
        pref[i] += pref[i-1];
    }

    int lo = 0, hi = pref[n-1];
    while(lo < hi) {
      int mid = (lo+hi)/2;

      bool poss = false;

      if(pref[n-1] - mid <= k)
        poss = true;

      for(int i = 1; i <= std::min(mid, n-1); i++) {
        int cur = pref[n-1-i]-mid+i+(a[0]-mid+i)*i;
        if(cur <= k)
          poss = true;
      }

      if(poss)
        hi = mid;
      else
        lo = mid+1;
    }

    std::cout << lo << std::endl;
  }

  return 0;
}