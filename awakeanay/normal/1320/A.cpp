/*
Author: AwakeAnay
Date: 01/03/2020
Time: 18:48:05
*/

#include <iostream>
#include <map>

#define int long long

signed main() {
  int n;
  std::cin >> n;

  std::map<int, int> m;
  int ans = 0;
  for(int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    m[i-x] += x;
    ans = std::max(ans, m[i-x]);
  }

  std::cout << ans << std::endl;

  return 0;
}