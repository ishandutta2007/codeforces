#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using ll = long long;
using ld = long double;

ld const eps = 0.0000001;
int const nmax = 1000;
int const lim = nmax * 10;
ld dp[5 + nmax], dp2[5 + nmax];
ld daily[5 + lim];

int main() {
  int n, q;
  std::cin >> n >> q;
  dp[0] = 1;
  for(int i = 1;i <= lim; i++) {
    for(int j = 0; j <= nmax; j++) {
      dp2[j] += dp[j] * j / n;
      dp2[j + 1] += dp[j] * (n - j) / n; 
    }
    for(int j = 0; j <= nmax; j++) {
      dp[j] = dp2[j];
      dp2[j] = 0;
    }
    daily[i] = dp[n];
  }

  for(int i = 1;i <= q; i++) {
    bool verdict = false;
    int p;
    std::cin >> p;
    for(int j = 1;j <= lim; j++) {
      if((p - eps) / 2000 <= daily[j]) {
        std::cout << j << '\n';
        verdict = true;
        break;
      }
    }
    assert(verdict == true);
  }
  return 0;
}