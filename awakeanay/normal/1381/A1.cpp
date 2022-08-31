#include <iostream>
#include <algorithm>
#include <vector>

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::string s[2];
    std::cin >> s[0] >> s[1];

    std::vector<int> ans[2];
    for(int m = 0; m < 2; m++) {
      for(int i = 0; i < n-1; i++) {
        if(s[m][i] != s[m][i+1])
          ans[m].push_back(i+1);
      }
      if(s[m][n-1] != '0')
        ans[m].push_back(n);
    }

    std::cout << ans[0].size() + ans[1].size() << " ";
    std::reverse(ans[1].begin(), ans[1].end());
    for(int j : ans[0])
      std::cout << j << " ";
    for(int j : ans[1])
      std::cout << j << " ";

    std::cout << std::endl;
  }

  return 0;
}