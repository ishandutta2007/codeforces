#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    int ans = 0;
    for(int i = 0; i < n; i++) {
      if(i+1 < n && s.substr(i, 2) == "00")
        ans += 2;
      if(i+2 < n && s.substr(i, 3) == "010")
        ans++;
    }

    std::cout << ans << std::endl;
  }

  return 0;
}