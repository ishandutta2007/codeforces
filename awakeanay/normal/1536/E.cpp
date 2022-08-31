#include <iostream>

#define int long long

const int MOD = 1000000007;

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, m;
    std::cin >> n >> m;

    int ans = 1;
    std::string s;
    bool add = 1;
    for(int i = 0; i < n; i++) {
      std::cin >> s;
      for(int j = 0; j < m; j++) {
        if(s[j] == '#')
          ans = (ans*2)%MOD;
        else
          add = 0;
      }
    }

    ans = (ans + MOD - add)%MOD;
    std::cout << ans << std::endl;
  }

  return 0;
}