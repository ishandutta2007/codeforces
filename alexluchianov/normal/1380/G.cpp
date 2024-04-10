#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <algorithm>

using ll = long long;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 300000;
int const modulo = 998244353;
int v[1 + nmax];
ll sum[1 + nmax];

int lgpow(int a, int b) {
  if(b == 0)
    return 1;
  else if(b == 1)
    return a;
  else {
    int result = lgpow(a, b / 2);
    if(b % 2 == 0)
      return 1LL * result * result % modulo;
    else
      return 1LL * result * result % modulo * a % modulo;
  }
}

ll eval(int n, int k) {
  int blocks = (n + k - 1) / k;
  ll result = 0;
  for(int i = 1; i <= blocks; i++) {
    result += 1LL * (i - 1) * (sum[std::min(i * k, n)] - sum[(i - 1) * k]) % modulo;
    if(result < 0)
      result += modulo;
    if(modulo <= result)
      result -= modulo;
  }
  return result;
}

int main() {
  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  std::sort(v + 1, v + n + 1);
  std::reverse(v + 1, v + n + 1);
  for(int i = 1;i <= n; i++) {
    sum[i] = sum[i - 1] + v[i];
    if(modulo <= sum[i])
      sum[i] -= modulo;
  }

  int inv = lgpow(n, modulo - 2);
  for(int i = 1;i <= n; i++)
    std::cout << 1LL * eval(n, i) * inv % modulo << " ";
  std::cout << '\n';
}