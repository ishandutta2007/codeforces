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

    int all_one = 1;
    int tot = 0;
    for(int i = 1; i+1 < n; i++) {
      tot += a[i] + a[i]%2;
    }

    for(int i = 1; i+1 < n; i++)
      all_one &= a[i] == 1;

    if(all_one || (n == 3 && a[1]%2 == 1)) {
      std::cout << -1 << std::endl;
      continue;
    }
    else
      std::cout << tot/2 << std::endl;
  }

  return 0;
}