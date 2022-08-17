#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, s;
    std::cin >> n >> s;

    int cur = 0;
    int a[n];
    int l = 0;
    int ans = -1;
    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
      if(a[i])
        cur++;
      if(cur == s) {
        ans = std::max(ans, i-l+1);
      }
      if(cur == s+1) {
        while(a[l] == 0) {
          l++;
        }
        l++;
        cur--;
        ans = std::max(ans, i-l+1);
      }
    }

    std::cout << (ans == -1 ? ans : n-ans) << std::endl;
  }

  return 0;
}