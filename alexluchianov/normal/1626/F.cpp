#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using ll = long long;

int const modulo = 998244353;
int const nmax = 16 * 9 * 5 * 7 * 11 * 13 * 17;

int dpbonus[5 + nmax];
int dp[2];

int main() {
  int n, start, x, y, k, m;
  std::cin >> n >> start >> x >> y >> k >> m;
  int coef = 1;
  for(int step = k; 1 <= step; step--) {
    int pos = (nmax - 1) - (nmax - 1) % step;

    dp[0] = (1LL * dp[0] * (n - 1) + dp[0] + coef) % modulo;
    for(int i = nmax - 1; 0 <= i; i--) {
      if(i < pos)
        pos -= step;
      dpbonus[i] = (1LL * dpbonus[i] * (n - 1) + dpbonus[pos] + 1LL * i * coef) % modulo;
    }
    coef = 1LL * coef * n % modulo;
  }

  int result = 0;
  for(int i = 0; i < n; i++, start = (1LL * start * x + y) % m) {
    result = (result + 1LL * dp[0] * (start - (start % nmax)) + dpbonus[start % nmax]) % modulo;
  }
  std::cout << result << '\n';
  return 0;
}