#include <iostream>
#include <vector>
#include <algorithm>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, k, x;
  std::cin >> n >> k >> x;

  int a[n];
  for(int i = 0; i < n; i++)
    std::cin >> a[i];

  std::sort(a, a + n);

  std::vector<int> types;

  for(int i = 1; i < n; i++) {
    types.push_back(std::max(0ll, (a[i]-1-a[i-1])/x));
  }

  std::sort(types.begin(), types.end());

  int ans = n;
  for(int j : types) {
    if(j <= k) {
      k -= j;
      ans--;
    }
  }

  std::cout << ans << std::endl;

  return 0;
}