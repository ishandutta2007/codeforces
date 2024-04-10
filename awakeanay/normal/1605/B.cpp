#include <iostream>
#include <vector>

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

    int c[2];
    c[0] = 0;
    for(int i = 0; i < n; i++) {
      if(s[i] == '0')
        c[0]++;
    }

    c[1] = n-c[0];
    std::vector<int> ans;
    for(int i = 0; i < n; i++) {
      if((i < c[0])^(s[i] == '0'))
        ans.push_back(i);
    }

    if(ans.size()) {
      std::cout << 1 << std::endl;
      std::cout << ans.size() << " ";
      for(int j : ans)
        std::cout << j+1 << " ";
      std::cout << std::endl;
    }
    else
      std::cout << 0 << std::endl;
  }

  return 0;
}