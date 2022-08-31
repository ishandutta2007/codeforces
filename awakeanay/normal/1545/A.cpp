#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define int long long

std::map<int, int> ans;

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::vector<int> type[2];
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      type[i%2].push_back(x);
    }
    std::sort(type[0].begin(), type[0].end());
    std::sort(type[1].begin(), type[1].end());

    int ct[2];
    ct[0] = ct[1] = 0;
    int ans[n];
    bool poss = true;
    for(int i = 0; i < n; i++) {
      ans[i] = type[i%2][ct[i%2]++];
      if(i && ans[i] < ans[i-1])
        poss = false;
    }

    std::cout << (poss ? "YES" : "NO") << std::endl;
  }

  return 0;
}