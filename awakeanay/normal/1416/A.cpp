#include <iostream>
#include <vector>
#include <algorithm>

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::vector<int> elems[n];
    for(int i = 0; i < n; i++) {
      elems[i].push_back(-1);
      elems[i].push_back(n);
      int x;
      std::cin >> x; x--;
      elems[x].push_back(i);
    }

    for(int i = 0; i < n; i++)
      std::sort(elems[i].begin(), elems[i].end());

    std::vector<int> max(n, 0);
    for(int i = 0; i < n; i++) {
      for(int j = 1; j < elems[i].size(); j++) {
        max[i] = std::max(max[i], elems[i][j]-elems[i][j-1]);
      }
    }

    std::vector<int> ans(n+1, -1);
    int cur = n;
    for(int i = 0; i < n; i++) {
      while(cur >= max[i]) {
        ans[cur] = i+1;
        cur--;
      }
    }

    for(int i = 1; i <= n; i++)
      std::cout << ans[i] << " ";
    std::cout << std::endl;
  }

  return 0;
}