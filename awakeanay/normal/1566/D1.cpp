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

    int ans = 0;
    int a[m];
    for(int i = 0; i < m; i++) {
      std::cin >> a[i];
      for(int j = 0; j < i; j++)
        if(a[j] < a[i])
          ans++;
    }

    std::cout << ans << std::endl;
  }

  return 0;
}