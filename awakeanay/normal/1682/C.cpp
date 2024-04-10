#include <iostream>
#include <map>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;
  
  while(t--) {
    int n;
    std::cin >> n;

    std::map<int, int> mp;
    int ct = 0;
    int ans = 0;
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      mp[x]++;
      if(mp[x] == 1)
        ct++;
      if(mp[x] == 2) {
        ct--;
        ans++;
      }
    }

    if(ct > 0) {
      ans += 1 + (ct-1)/2;
    }

    std::cout << ans << std::endl;
  }

  return 0;
}