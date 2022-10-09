#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <algorithm>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000000;
int const modulo = 1000000007;

class Mint{
private:
  int number;
  void gcd(int a, int b, int &x, int &y) {
    if(b == 0) {
      x = 1;
      y = 0;
    } else {
      gcd(b, a % b, x, y);
      int aux = x;
      x = y;
      y = aux - a / b * y;
    }
  }
public:
  Mint(int number_ = 0) {
    number = number_ % modulo;
  }
  Mint(ll number_ ) {
    number = number_ % modulo;
  }

  Mint operator + (Mint a) {
    return number + a.number;
  }
  Mint operator - (Mint a) {
    return modulo + number - a.number;
  }
  Mint operator * (Mint a) {
    return 1LL * number * a.number;
  }
  Mint operator / (Mint a) {
    int x, y;
    gcd(a.number, modulo, x, y);
    x %= modulo;
    if(x < 0)
      x += modulo;
    return 1LL * number * x;
  }
  friend std::ostream &operator << (std::ostream &output, Mint number) {
    output << number.number;
    return output;
  }
};
Mint fact[1 + nmax];

void precompute() {
  fact[0] = 1;
  for(int i = 1;i <= nmax; i++)
    fact[i] = fact[i - 1] * i;
}

Mint lgpow(Mint a, int b) {
  if(b == 0)
    return 1;
  else if(b == 1)
    return a;
  else { 
    Mint result = lgpow(a, b / 2);
    if(b % 2 == 0)
      return result * result;
    else
      return result * result * a;
  }
}

Mint comb(int n, int k) {
  assert(0 <= k && k <= n);
  return fact[n] / (fact[n - k] * fact[k]);
}

int main() {
  int n, m;
  std::cin >> n >> m;
  Mint result(lgpow(m, n));
  precompute();

  for(int dif = 0; dif < n; dif++) {
    result = result + lgpow(m, n - dif) * lgpow(m - 1, dif) * (comb(n, dif + 1) );
  }
  std::cout << result;
  return 0;
}