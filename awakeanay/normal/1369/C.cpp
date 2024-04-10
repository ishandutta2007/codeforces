#include <algorithm>
#include <iostream>

#define int long long

signed main() {
  int t;
  std::cin >> t;
  
  while(t--) {
    int n, k;
    std::cin >> n >> k;

    int a[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    int w[k];
    for(int i = 0; i < k; i++)
      std::cin >> w[i];

    std::sort(a, a+n);
    std::sort(w, w+k);

    int ans = 0;
    int l = 0, r = n-1;
    for(int i = 0; i < k; i++) {
      if(w[i] == 1) {
        ans += 2*a[r];
        r--;
      }
      else
        break;
    }


    for(int i = k-1; i >= 0; i--) {
      if(w[i] == 1)
        break;
      ans += a[r];
      ans += a[l];
      l += w[i]-1;
      r--;
    }

    std::cout << ans << std::endl;
  }

  return 0;
}