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
    bool poss = true;
    int rot = -1;
    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
      if(a[i] == 1) {
        poss &= rot == -1;
        rot = i;
      }
    }

    std::rotate(a, a+rot, a+n);

    for(int i = 1; i < n; i++) {
      poss &= a[i] >= 2;
      poss &= a[i] <= a[i-1] + 1;
    }

    std::cout << (poss ? "YES" : "NO") << std::endl;
  }

  return 0;
}