#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, m;
    std::cin >> n >> m;

    int a[4] = {1, 0, 0, 1};
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        std::cout << (a[j%4]^a[i%4]) << " ";
      }
      std::cout << "\n";
    }
  }

  return 0;
}