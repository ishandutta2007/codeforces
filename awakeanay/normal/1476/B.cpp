#include <iostream>

#define int long long

const int INF = 1000000000000000;

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, k;
    std::cin >> n >> k;

    int pref[n+1];
    pref[0] = 0;
    for(int i = 1; i <= n; i++) {
      std::cin >> pref[i];
      pref[i] += pref[i-1];
    }

    int l = 0, r = INF;
    while(l < r) {
      int m = (l+r)/2;
      bool check = true;
      for(int i = 2; i <= n; i++) {
        if((pref[i]-pref[i-1])*100 > k*(pref[i-1]+m)) {
          check = false;
          break;
        }
      }

      if(check)
        r = m;
      else
        l = m+1;
    }

    std::cout << l << std::endl;
  }

  return 0;
}