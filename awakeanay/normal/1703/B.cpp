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

    std::vector<int> ct(26, 0);
    int ans = 0;
    for(int i = 0; i < n; i++) {
      char c;
      std::cin >> c;
      ct[c-'A']++;
      ans++;
      if(ct[c-'A'] == 1)
        ans++;
    }

    std::cout << ans << std::endl;
  }

  return 0;
}