#include <iostream>
#include <algorithm>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    bool corr = true;

    std::pair<int, int> s[4];
    for(int i = 0; i < 4; i++) {
      std::cin >> s[i].first;
      s[i].second = i;
    }

    std::sort(s, s+4);

    int sum = s[2].second + s[3].second;
    if(sum == 1 || sum == 5)
      corr = false;

    std::cout << (corr ? "YES" : "NO") << std::endl;
  }

  return 0;
}