#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int first = -1, last = -1;
    int ct = 0;
    int n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    int ans = 0;
    for(int i = 0; i < n; i++) {
      if(s[i] == '1') {
        if(first == -1)
          first = i;
        last = i;
        ct++;
      }
      int cur = s[i] == '1';
      ans += cur*11;
    }

    int val = ans;
    if(ct == 0) {
      ans = 0;
    }
    else if(ct == 1) {
      if(n-1-last <= k) {
        ans = std::min(ans, val - 10);
      }
      if(first <= k)
        ans = std::min(ans, val - 1);
    }
    else if(ct > 1) {
      if(n-1-last <= k) {
        ans = std::min(ans, val - 10);
      }
      if(first <= k)
        ans = std::min(ans, val - 1);

      if(first + (n-1-last) <= k)
        ans = std::min(ans, val - 11);
    }


    std::cout << ans << std::endl;
  }

  return 0;
}