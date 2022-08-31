#include <iostream>

signed main() {
  int t;
  t = 1;

  while(t--) {
    int n, m;
    std::cin >> n >> m;

    std::string s, p;
    std::cin >> s >> p;

    int left[m];
    int right[m];

    int j = 0;
    for(int i = 0; i < n; i++) {
      if(s[i] == p[j]) {
        left[j] = i;
        j++;
        if(j == m)
          break;
      }
    }

    j = m-1;
    for(int i = n-1; i >= 0; i--) {
      if(s[i] == p[j]) {
        right[j] = i;
        j--;
        if(j < 0)
          break;
      }
    }

    int ans = 0;
    for(int i = 0; i+1 < m; i++) {
      ans = std::max(ans, right[i+1]-left[i]);
    }

    std::cout << ans << std::endl;
  }

  return 0;
}