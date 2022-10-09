#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <iomanip>
using ll = long long;
using ld = long double;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int const sigma = 60;
int v[1 + 2 * nmax][2];

int main() {
  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i][0] >> v[i][1];
  for(int i = 1;i <= n; i++) {
    v[i + n][0] = v[i][0];
    v[i + n][1] = v[i][1];
  }
  int lim = std::min(sigma, n - 1);
  ld result = 0, result2 = 0;
  ld bigcoef = 1;
  for(int i = 1;i <= n; i++)
    bigcoef /= 2;
  for(int h = 1; h <= lim; h++) {
    ld coef = 1.0 / (1LL << (h + 1));
    for(int i = 1;i <= n; i++) {
      int j = i + h;
      int x = fabs(v[i][0] - v[j][0]);
      int y = fabs(v[i][1] - v[j][1]);
      int gcd = std::__gcd(x, y);
      result += (1LL * v[i][0] * v[j][1] - 1LL * v[i][1] * v[j][0]) * (coef - bigcoef);
      result2 += gcd * (coef - bigcoef);
    }
  }
  ld alfa = 1LL * n * (n - 1) / 2 + n + 1;
  result = result / 2 - result2 / 2;
  
  ld coef2 = 1 / alfa;
  for(int i = 1;i <= n; i++)
    coef2 = coef2 * 2;
  coef2 -= 1;
  ld coef = 1 / coef2;
  std::cout << std::setprecision(9) << std::fixed << result + result * coef + 1 << '\n';

  return 0;
}