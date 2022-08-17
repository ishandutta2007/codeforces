#include <iostream>
#include <vector>
#include <algorithm>

#define int long long

std::vector<int> v = {1200, 1400, 1600, 1900, 2100, 2300, 2400, 2600, 3000};

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int r;
  std::cin >> r;

  std::cout << (*std::upper_bound(v.begin(), v.end(), r)) << std::endl;

  return 0;
}