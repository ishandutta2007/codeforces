#include <iostream>
#include <vector>
#include <algorithm>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int a[n];
    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
    }

    std::vector<std::pair<std::pair<int, int>, int> > ans;
    for(int j = 1; j < n; j++) {
      int k = j;
      while(k-1 >= 0 && a[k-1] > a[j])
        k--;
      if(k != j) {
        ans.push_back({{k, j}, j-k});
        std::rotate(a+k, a+j, a+j+1);
      }
    }

    std::cout << ans.size() << std::endl;
    for(auto j : ans)
      std::cout << j.first.first+1 << " " << j.first.second+1 << " " << j.second << std::endl;
  }

  return 0;
}