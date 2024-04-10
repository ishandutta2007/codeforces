#include <iostream>
#include <vector>

#define int long long

signed main() { 
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int s[n];
    for(int i = 0; i < n; i++)
      std::cin >> s[i];

    std::vector<int> t(n, 0);
    for(int j = 0; j < n; j++) {
      if(j+1 < n)
        t[j+1] += std::max(0ll, t[j]-s[j]+1);
      for(int k = j+2; k < n && k <= j + s[j]; k++) {
        t[k]++;
      }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
      ans += std::max(0ll, s[i]-t[i]-1);
    }

    std::cout << ans << std::endl;
  }

  return 0;
}