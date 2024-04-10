#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    std::string s;
    std::cin >> s;

    int n = s.length();
    int last[2];
    last[0] = last[1] = -1;
    int ans = 0;

    for(int i = 0; i < n; i++) {
      if(s[i] == '0') {
        last[i%2] = i;
      }
      else if(s[i] == '1') {
        last[(i%2)^1] = i;
      }
      ans += i-std::min(last[0], last[1]);
    }

    std::cout << ans << std::endl;
  }

  return 0;
}