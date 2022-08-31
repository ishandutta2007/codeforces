#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

#define int long long

signed main() {
  int n;
  std::cin >> n;

  std::vector<std::vector<int> > dp(n+1, std::vector<int>(10001, 10001));

  dp[0][0] = 0;

  int suma = 0, sumb = 0;
  for(int i = 0; i < n; i++) {
    int a, b;
    std::cin >> a >> b;
    suma += a; sumb += b;
    for(int j = i; j >= 0; j--) {
      for(int k = 10000-b; k >= 0; k--) {
        dp[j+1][k+b] = std::min(dp[j][k] + a, dp[j+1][k+b]);
      }
    }
  }

  for(int k = 1; k <= n; k++) {
    double ans = 0.00000000;
    for(int i = 0; i <= 10000; i++) {
      ans = std::max(ans, std::min(round(suma) - round(dp[n-k][i]), round(sumb) - ((double)i)/2));
    }
    std::cout << std::setprecision(10) << std::fixed << ans << " ";
  }
  
  return 0;
}