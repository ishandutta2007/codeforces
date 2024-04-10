#include <iostream>
#include <vector>
#include <algorithm>

signed main() {
  int n;
  std::cin >> n;

  int a[n+1];
  std::pair<int, int> rev[n];
  for(int i = 1; i <= n; i++) {
    std::cin >> a[i];
    rev[i-1].first = a[i];
    rev[i-1].second = i;
  }

  std::sort(rev, rev+n);

  std::vector<std::pair<int, int> > ans;
  for(int i = 0; i < n; i++) {
    int x = rev[i].first;
    for(int j = n; j > rev[i].second; j--) {
      if(a[j] < rev[i].first) {
        ans.push_back({rev[i].second, j});
      }
    }
  }

  std::cout << ans.size() << std::endl;
  for(std::pair<int, int> x : ans)
    std::cout << x.first << " " << x.second << std::endl;
  return 0;
}