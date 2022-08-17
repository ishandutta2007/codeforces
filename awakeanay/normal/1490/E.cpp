#include <iostream>
#include <algorithm>
#include <vector>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::pair<int, int> a[n];
    for(int i = 0; i < n; i++) {
      std::cin >> a[i].first;
      a[i].second = i;
    }

    std::sort(a, a+n);

    int pref[n];
    for(int i = 0; i < n; i++) {
      pref[i] = a[i].first;
      if(i) pref[i] += pref[i-1];
    }

    std::vector<int> ans;

    ans.push_back(a[n-1].second);
    for(int i = n-1; i > 0; i--) {
      if(2*a[i].first <= pref[i])
        ans.push_back(a[i-1].second);
      else
        break;
    }
    std::sort(ans.begin(), ans.end());

    std::cout << ans.size() << std::endl;
    for(int j : ans)
      std::cout << j+1 << " ";
    std::cout << std::endl;
  }
  
  return 0;
}