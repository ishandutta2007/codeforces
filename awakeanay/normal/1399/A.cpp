#include <iostream>
#include <algorithm>

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

    std::sort(a, a+n);
    bool poss = true;
    for(int i = 1; i < n; i++) {
      if(a[i]-a[i-1] > 1)
        poss = false;
    }

    std::cout << (poss ? "YES" : "NO") << std::endl;
  }

  return 0;
}