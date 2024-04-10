#include <iostream>

#define int long long

signed main() {
  int n;
  std::cin >> n;

  int a[n];
  for(int i = 0; i < n; i++)
    std::cin >> a[i];

  int ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = i; j < n; j++) {
      for(int k = j; k < n; k++) {
        ans = std::max(ans, a[i]|a[j]|a[k]);
      }
    }
  }

  std::cout << ans << std::endl;

  return 0;
}