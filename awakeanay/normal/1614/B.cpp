#include <iostream>
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

    std::pair<int, int> a[n];
    for(int i = 0; i < n; i++) {
      std::cin >> a[i].first;
      a[i].second = i+1;
    }

    std::sort(a, a+n);
    std::reverse(a, a+n);

    int l = -1, r = 1;
    int ans[n+1];
    ans[0] = 0;
    int val = 0;
    int cur = 0;
    for(int i = 0; i < n; i++) {
      if(i%2) {
        val += 2*r*a[i].first;
        ans[a[i].second] = r++;
      }
      else {
        val -= 2*l*a[i].first;
        ans[a[i].second] = l--;
      }

    }

    std::cout << val << std::endl;
    for(int i = 0; i <= n; i++)
      std::cout << ans[i] << " ";
    std::cout << std::endl;
  }

  return 0;
}