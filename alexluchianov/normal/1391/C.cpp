#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using ll = long long;
#define MIN(a,b ) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax =   1000000;
int const modulo = 1000000007;
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
int main() {
  int n;
  std::cin >> n;
  int result = 1, result2 = 1;
  for(int i = 1;i <= n; i++)
    result = 1LL * result * i % modulo;
  std::cout << (modulo + result - lgpow(2, n - 1)) % modulo;
  return 0;
}