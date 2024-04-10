#include <iostream>
#include <vector>

signed main() {
  int n;
  std::cin >> n;
  
  std::vector<std::pair<int, int> > ans;

  ans.push_back({0, 0});
  for(int j = 1; j <= n; j++) {
    ans.push_back({2*j-1, 2*j-1});
    ans.push_back({2*j-2, 2*j-1});
    ans.push_back({2*j, 2*j-1});
    ans.push_back({2*j-1, 2*j-2});
    ans.push_back({2*j-1, 2*j});

    if(j < n) {
      ans.push_back({2*j-1, 2*j+1});
      ans.push_back({2*j+1, 2*j-1});
    }
    else
      ans.push_back({2*j, 2*j});
  }

  std::cout << ans.size() << std::endl;
  for(int i = 0; i < ans.size(); i++)
    std::cout << ans[i].first << " " << ans[i].second << std::endl;

  return 0;
}