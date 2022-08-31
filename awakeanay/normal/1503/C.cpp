#include <iostream>
#include <algorithm>

#define int long long

signed main() {
  int n;
  std::cin >> n;

  std::pair<int, int> list[n];
  int ans = 0;
  for(int i = 0; i < n; i++) {
    std::cin >> list[i].first >> list[i].second;
    ans += list[i].second;
    list[i].second += list[i].first;
  }

  std::sort(list, list+n);

  int max = 0;
  for(int i = 0; i+1 < n; i++) {
    max = std::max(max, list[i].second);
    if(max < list[i+1].first)
      ans += list[i+1].first-max;
  }
  std::cout << ans << std::endl;

  return 0;
}