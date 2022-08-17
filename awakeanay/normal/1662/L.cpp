#include <iostream>
#include <algorithm>
#include <vector>

#define int long long

signed main() {
  int n, v;
  std::cin >> n >> v;

  int a[n+1], t[n+1];
  std::pair<int, int> help[n+1];
  a[0] = t[0] = 0;
  for(int i = 1; i <= n; i++)
    std::cin >> t[i];
  for(int i = 1; i <= n; i++)
    std::cin >> a[i];

  for(int i = 0; i <= n; i++) {
    help[i] = {-a[i]-t[i]*v, a[i]-t[i]*v};
  }

  std::sort(help, help+n+1);

  int ans = -1;
  std::vector<int> lis;
  for(int i = 0; i <= n; i++) {
    auto u = std::upper_bound(lis.begin(), lis.end(), help[i].second);
    if(u == lis.end()) {
      lis.push_back(help[i].second);
    }
    else
      (*u) = help[i].second;

    if(help[i].first == 0 && help[i].second == 0) {
      ans = std::upper_bound(lis.begin(), lis.end(), help[i].second)-lis.begin();
    }
  }

  std::cout << ans-1 << std::endl;

  return 0;
}