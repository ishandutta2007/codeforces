#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, m;
    std::cin >> m >> n;

    int ans = 0;
    for(int i = 0; i < n; i++)
      ans += i+1;
    for(int j = 1; j < m; j++) {
      ans += (j+1)*n;
    }
    std::cout << ans << std::endl;
  }

  return 0;
}