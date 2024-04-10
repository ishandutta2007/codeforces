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

    int a[n], b[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];
    for(int i = 0; i < n; i++)
      std::cin >> b[i];

    std::sort(a, a+n);
    std::sort(b, b+n);

    bool poss = true;
    int ai = 0, bi = 0;
    int ct = 0;

    while(ai < n && bi < n) {
      if(a[ai] == b[bi] || a[ai]+1 == b[bi]) {
        ai++;
        bi++;
        ct++;
      }
      else if(a[ai] > b[bi])
        bi++;
      else
        ai++;
    }

    std::cout << (ct == n ? "YES" : "NO") << std::endl;
  }

  return 0;
}