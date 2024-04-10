#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int a[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    int m;
    std::cin >> m;

    int cur = 0;
    for(int i = 0; i < m; i++) {
      int x;
      std::cin >> x;
      cur = (cur+x)%n;
    }

    std::cout << a[cur] << "\n";
  }

  return 0;
}