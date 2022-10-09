#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 30;

int n, m, r;
int v[1 + nmax], b[1 + nmax], coef[1 + nmax], p[1 + nmax];
int rem[1 + nmax][1 + nmax];

void backt(int step, int last, ll &result) {
  if(step % 2 == m % 2) {
    ll sum = 0;
    for(int i = 1;i <= n; i++)
      sum += 1LL * v[i] * coef[i];
    result = std::max(result, sum);
  }
  if(step < m) {
    if(last != 1) {
      for(int i = 1;i <= n; i++)
        rem[step][i] = v[i];
      for(int i = 1;i <= n; i++)
        v[i] ^= b[i];
      backt(step + 1, 1, result);
      for(int i = 1;i <= n; i++)
        v[i] = rem[step][i];
    }
    for(int i = 1;i <= n; i++)
      rem[step][i] = v[i];
    for(int i = 1;i <= n; i++)
      v[i] = rem[step][p[i]] + r;
    backt(step + 1, 2, result);
    for(int i = 1;i <= n; i++)
      v[i] = rem[step][i];
  }
}

int main() {
  std::cin >> n >> m >> r;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  for(int i = 1;i <= n; i++)
    std::cin >> b[i];
  for(int i = 1;i <= n; i++)
    std::cin >> coef[i];
  for(int i = 1;i <= n; i++)
    std::cin >> p[i];
  ll result = -1000000000000000000LL;
  backt(0, 2, result);
  std::cout << result;
  return 0;
}