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

    int k;
    std::cin >> k;

    if(k == n-1 && n == 4) {
      std::cout << -1 << std::endl;
      continue;
    }

    std::vector<int> ans;
    for(int j = 0; j < n/2; j++) {
      ans.push_back(j);
      ans.push_back(n-1-j);
    }

    if(k != 0 && k != n-1) {
      for(int j = 0; j < n; j++) {
        if(ans[j] == k || ans[j] == 0)
          ans[j] = k-ans[j];
      }
    }
    else if(k == n-1) {
      for(int j = 0; j < n; j++) {
        if(ans[j] == 0 || ans[j] == n-2)
          ans[j] = n-2-ans[j];
        if(ans[j] == 2 || ans[j] == 3)
          ans[j] = 5-ans[j];
      }
    }

    for(int i = 0; i < n/2; i++) {
      std::cout << ans[2*i] << " " << ans[2*i+1] << std::endl;
    }
  }

  return 0;
}