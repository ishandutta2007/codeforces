#include <iostream>
#include <map>

#define int long long

const int MOD = 1000000007;

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::map<int, int> pref;

    int cur = 0;
    int ans = 1;
    pref[cur] = 1;
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      int save = ans;
      ans = (2*ans - pref[cur] + MOD)%MOD;
      pref[cur] = save;
      cur += x;
    }

    std::cout << ans << std::endl;
  }
  
  return 0;
}