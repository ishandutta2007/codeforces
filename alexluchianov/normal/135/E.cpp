#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 3000000;
int const modulo = 1000000007;

int fact[1 + nmax];

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

int inverse(int number) {
  return lgpow(number, modulo - 2);
}

int comb(int n, int k) {
  if(0 <= k && k <= n)
    return 1LL * fact[n] * inverse(1LL * fact[k] * fact[n - k] % modulo) % modulo;
  return 0;
}

int comb2(int n, int k) {
  if(0 <= k && k <= n)
    return 1LL * fact[n] * inverse(1LL * fact[n - k] % modulo) % modulo;
  return 0;
}

int solve(int n, int k, int w) {
  int stop = n - w + 1, start = w;

  if(start <= stop) {
    int l = stop - start + 1;
    return 1LL * comb2(k, l) *
           comb2(k - l, start - 1) % modulo *
           comb2(k - l, n - stop) % modulo;
  } else 
    return 1LL * comb2(k, stop) % modulo *
                 comb2(k, n + 1 - start)  % modulo  
                 * lgpow(k, start - stop - 1) % modulo;
}

int main() {
  fact[0] = 1;
  for(int i = 1; i <= nmax; i++)
    fact[i] = 1LL * fact[i - 1] * i % modulo;

  int k, w;
  std::cin >> k >> w;
  
  int result = 0;
  for(int n = w + 1; n <= w + 2 * k; n++) {
    result += solve(n, k, w + 1) - solve(n, k, w);
    if(modulo <= result)
      result -= modulo;
    if(result < 0)
      result += modulo;
  }
  std::cout << result << '\n';
  return 0;
}