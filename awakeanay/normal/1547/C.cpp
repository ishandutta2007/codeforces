#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int k, n, m;
    std::cin >> k >> n >> m;

    int a[n+1], b[m+1];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];
    for(int i = 0; i < m; i++)
      std::cin >> b[i];
    a[n] = b[m] = 5000;

    int ai = 0, bi = 0;
    int cur[n+m];

    int i = 0;
    bool poss = true;
    while(ai < n || bi < m) {
      while(ai < n && a[ai] == 0) {
        cur[i++] = 0;
        k++;
        ai++;
      }
      while(bi < m && b[bi] == 0) {
        cur[i++] = 0;
        k++;
        bi++;
      }

      if(i == n+m)
        break;

      if(a[ai] > k && b[bi] > k) {
        poss = false;
        break;
      }
      else if(a[ai] <= k) {
        cur[i++] = a[ai];
        ai++;
      }
      else {
        cur[i++] = b[bi];
        bi++;
      }
    }

    if(poss) {
      for(int j : cur)
        std::cout << j << " ";
      std::cout << std::endl;
    }
    else
      std::cout << -1 << std::endl;
  }

  return 0;
}