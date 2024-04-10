#include <iostream>
#include <vector>

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    std::string s;
    std::cin >> s;
  
    int n = s.length();
    int ans = 0;

    std::vector<int> count(10, 0);
    for(int i = 0; i < n; i++) {
      int val = s[i]-'0';
      count[val]++;
      ans = std::max(ans, count[val]);
    }

    for(int i = 0; i < 10; i++) {
      for(int j = i+1; j < 10; j++) {
        int last = -1;
        int cur = 0;
        for(int k = 0; k < n; k++) {
          int val = s[k]-'0';
          if(val == i || val == j) {
            if(val != last) {
              cur++;
              last = val;
              if(cur % 2 == 0)
                ans = std::max(ans, cur);
            }
          }
        }
      }
    }

    std::cout << n-ans << std::endl;
  }

  return 0;
}