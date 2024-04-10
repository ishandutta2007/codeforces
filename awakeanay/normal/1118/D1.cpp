#include <iostream>
#include <algorithm>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;

  int a[n];
  int sum = 0;
  for(int i = 0; i < n; i++) {
    std::cin >> a[i];
    sum += a[i];
  }

  if(sum < m) {
    std::cout << -1 << std::endl;
    return 0;
  }

  std::sort(a, a+n);
  std::reverse(a, a+n);

  int ans = n;
  for(int i = 1; i <= n; i++) {
    int cur = 0;
    int add = 0;
    for(int j = 0; j < n; j++) {
      add += a[j];
      add -= cur/i;
      if(add >= m)
        ans = std::min(ans, i);
      cur++;
    }
  }

  std::cout << ans << std::endl;

  return 0;
}