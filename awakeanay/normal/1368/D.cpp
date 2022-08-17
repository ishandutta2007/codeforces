#include <iostream>
#include <algorithm>

#define int long long

signed main() {
  int n;
  std::cin >> n;

  int a[20][n];
  for(int i = 0; i < n; i++) {
    int x;
    std::cin >> x;

    for(int j = 0; j < 20; j++) {
      a[j][i] = (x >> j)&1;
    }
  }

  for(int i = 0; i < 20; i++)
    std::sort(a[i], a[i]+n);

  int ans = 0;
  for(int i = 0; i < n; i++) {
    int cur = 0;
    for(int j = 0; j < 20; j++) {
      if(a[j][i])
        cur += (1 << j);
    }

    ans += cur*cur;
  }

  std::cout << ans << std::endl;
  return 0;
}