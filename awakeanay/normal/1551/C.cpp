#include <iostream>
#include <vector>
#include <algorithm>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::string s[n];
    for(int i = 0; i < n; i++)
      std::cin >> s[i];

    int ans = 0;
    for(int i = 0; i < 5; i++) {
      std::vector<int> poss;
      for(int j = 0; j < n; j++) {
        int cur = 0;
        for(char k : s[j]) {
          if(k == 'a' + i)
            cur--;
          else
            cur++;
        }
        poss.push_back(cur);
      }

      std::sort(poss.begin(), poss.end());

      int cur = 0;
      int cans = 0;
      for(int j : poss) {
        if(cur + j < 0) {
          cur += j;
          cans++;
        }
      }

      ans = std::max(ans, cans);
    }

    std::cout << ans << std::endl;
  }

  return 0;
}