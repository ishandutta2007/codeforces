
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;
using ud = unsigned int;

int const nmax = 100000;
ud dp[5 + nmax];
ud dp2[5 + nmax];

int main() {
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;

  dp[0] = 1;
  
  int per = n / 2;

  for(int i = 0;i < n; i++) {
    ud last = 0;
    int lim = std::min(i + 1, n - i + 3);
    
    if(s[i] == '?') {
      if(i % 2 == 0) {
        dp2[0] = dp[1];
        for(int j = 1; j <= lim; j++)
          dp2[j] = dp[j - 1] + dp[j + 1];
      } else {
        dp[0] = dp2[1];
        for(int j = 1; j <= lim; j++)
          dp[j] = dp2[j - 1] + dp2[j + 1];
      }
    } else {
      per--;
      if(i % 2 == 0) {
        dp2[0] = 0;
        for(int j = 1; j <= lim ; j++)
          dp2[j] = dp[j - 1];
      } else {
        dp[0] = 0;
        for(int j = 1; j <= lim; j++)
          dp[j] = dp2[j - 1];
      }
    }
  }
  if(n % 2 == 0) {
  for(int i = 0; i < per; i++)
    dp[0] = dp[0] * 25;
  std::cout << dp[0] << '\n';
  } else
    std::cout << 0 << '\n';
  return 0;
}