#include <iostream>

#define int long long

const int LOG = 20;

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    std::string s;
    std::cin >> s;

    int n = s.length();
    int zeroes = 0;
    int ans = 0;
    for(int i = 0; i < n; i++) {
      if(s[i] == '0') {
        zeroes++;
        continue;
      }

      int cur = 0;
      for(int j = i; j < std::min(i+LOG, n); j++) {
        int v = s[j]-'0';
        cur *= 2;
        cur += v;

        if(zeroes+j-i+1 >= cur)
          ans++;
      }

      zeroes = 0;
    }

    std::cout << ans << std::endl;
  }

  return 0;
}