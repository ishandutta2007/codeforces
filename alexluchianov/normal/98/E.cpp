#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>

using ll = long long;
using ld = long double;

int const nmax = 1000;
ld dp[5 + nmax][5 + nmax];

int main() {
  int n, m;
  std::cin >> n >> m;
  dp[0][0] = 1;
  for(int sum = 1; sum <= n + m; sum++)
    for(int i = 0; i <= sum; i++) {
      int j = sum - i;
      if(i <= std::max(n, m) && j <= std::max(n, m)) {
        ld a = 0, b = 0, c = 0, d = 0;
        if(0 == j) {
          dp[i][j] = 1;
          continue;
        } else if(0 == i) {
          dp[i][j] = 1.0 / (j + 1);
          continue;
        }
        a = 1.0 * j / (j + 1) * (1 - dp[j - 1][i]) + (1.0 / (j + 1));
        b = 1.0 * j / (j + 1) * (1 - dp[j - 1][i]);
        c = (1 - dp[j][i - 1]);
        d = 1;
        dp[i][j] = std::max((ld)(1.0 / (j + 1)), (a * d - b * c) / (a - b - c + d));
      }
    }
  std::cout << std::setprecision(9) << std::fixed << dp[n][m] << " " << 1 - dp[n][m] << '\n'; 
  return 0;
}