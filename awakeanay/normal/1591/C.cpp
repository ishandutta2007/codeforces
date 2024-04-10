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
    int n, k;
    std::cin >> n >> k;

    std::vector<int> left, right;
    left.push_back(0);
    right.push_back(0);

    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      if(x < 0)
        left.push_back(-x);
      else
        right.push_back(x);
    }

    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    int ans = 0;
    int m = left.size();
    for(int i = m-1; i >= 0; i-=k) {
      ans += 2*left[i];
    }

    m = right.size();
    for(int i = m-1; i >= 0; i-=k) {
      ans += 2*right[i];
    }

    ans -= std::max(left.back(), right.back());
    std::cout << ans << std::endl;
  }


  return 0;
}