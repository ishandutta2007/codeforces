#include <iostream>

#define int long long

int gcd(int a, int b) {
  if(a == 0)
    return b;
  return gcd(b%a, a);
}

const int LOGN = 18;

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

    if(n == 1) {
      std::cout << 1 << std::endl;
      continue;
    }

    int b[n-1];
    for(int i = 1; i < n; i++) {
      b[i-1] = a[i] - a[i-1];
      if(b[i-1] < 0)
        b[i-1] *= -1;
    }

    n--;

    int gd[LOGN][n+1];
    for(int i = 0; i < n; i++) {
      gd[0][i] = b[i];
    }
    gd[0][n] = 1;

    n++;

    for(int i = 1; i < LOGN; i++) {
      for(int j = 0; j < n; j++)
        gd[i][j] = 1;
      for(int j = 0; j + (1 << i) <= n; j++) {
        gd[i][j] = gcd(gd[i-1][j], gd[i-1][j + (1 << (i-1))]);
        //std::cout << i << " " << j << " " << gd[i][j] << std::endl;
      }
    }

    int ans = 0;
    for(int i = 0; i+1 < n; i++) {
      int cur = 0;
      int len = 0;
      int l = i;
      for(int j = LOGN-1; j >= 0; j--) {
        int ngd = gcd(cur, gd[j][l]);
        if(ngd != 1) {
          len += (1 << j);
          l += (1 << j);
          cur = ngd;
        }
      }

      ans = std::max(ans, len);
    }

    std::cout << ans+1 << std::endl;
  }

  return 0;
}