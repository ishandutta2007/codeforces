#include <iostream>

#define int long long 

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, k, z;
    std::cin >> n >> k >> z;

    int a[n];
    int pref[n+1];
    int info[n+1];
    int max = 0;
    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
      if(i) max = std::max(max, a[i]+a[i-1]);
      info[i] = max;
      pref[i] = a[i];
      if(i) pref[i] += pref[i-1];
    }

    info[n] = info[n-1];
    pref[n] = pref[n-1];

    int ans = pref[k];
    for(int i = 1; i < n; i++) {
      for(int j = 1; j <= z; j++) {
        if(2*j-1+i > k)
          break;
        int left = k-(2*j-1+i);
        ans = std::max(ans, pref[i] + j*a[i-1] + (j-1)*a[i] + pref[i-1+left]-pref[i-1]);
      }
    }
    

    std::cout << ans << std::endl;
  }

  return 0;
}