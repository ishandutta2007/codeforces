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
    int b[n];

    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
      b[i] = a[i];
    }

    std::sort(b, b+n);

    int rev[n];
    for(int i = 0; i < n; i++) {
      a[i] = std::lower_bound(b, b+n, a[i])-b;
      rev[a[i]] = i;
    }

    int poss[n][n];
    for(int i = 0; i < n; i++)
      poss[i][i] = 1;

    int ans = n-1;
    for(int i = 0; i < n; i++) {
      for(int j = i+1; j < n; j++) {
        if(poss[i][j-1] && rev[j] > rev[j-1])
          poss[i][j] = 1;
        else
          poss[i][j] = 0;
        if(poss[i][j]) ans = std::min(ans, n-(j-i+1));
      }
    }

    std::cout << ans << std::endl;
  }

  return 0;
}