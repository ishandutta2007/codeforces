#include <iostream>
#include <vector>

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int a[n];
    int sum = 0;
    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
      sum += a[i];
    }

    if(sum%n != 0) {
      std::cout << -1 << std::endl;
      continue;
    }

    std::vector<std::pair<int, std::pair<int, int> > > ans;
    for(int i = 1; i < n; i++) {
      if(a[i]%(i+1) != 0) {
        ans.push_back({1, {i+1, i+1-(a[i]%(i+1))}});
        a[i] += i+1-(a[i]%(i+1));
      }
      ans.push_back({i+1, {1, a[i]/(i+1)}});
    }

    for(int i = 1; i < n; i++) {
      ans.push_back({1, {i+1, sum/n}});
    }

    std::cout << ans.size() << std::endl;
    for(int i = 0; i < ans.size(); i++) {
      std::cout << ans[i].first << " " << ans[i].second.first << " " << ans[i].second.second << std::endl;
    }
  }

  return 0;
}