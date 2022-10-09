#include <iostream>
#include <vector>

using ll = long long;

int const nmax = 200000;
int const modulo = 1000000007;

struct Mint{
private:
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
  int number;
  Mint(int val_ = 0) {
    number = val_ % modulo;
  }
  Mint(ll val_ ) {
    number = val_ % modulo;
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
};
Mint fact[1 + nmax];

Mint comb(int n, int k) {
  if(0 <= k && k <= n)
    return fact[n] / (fact[k] * fact[n - k]);
  return 0;
}

Mint combrep(int n, int k) {
  if(n == 0 && k == 0)
    return 1;
  return comb(n - 1, k - 1);
}

int main() {
  fact[0] = 1;
  for(int i = 1; i <= nmax; i++)
    fact[i] = fact[i - 1] * i;
  int n, m, q;
  std::cin >> n >> m >> q;
  Mint total = 0, good = 0;
  
  for(int i = 1; i <= n + m; i++) {
    //food first
    int n1 = i / 2 + i % 2;
    int n2 = i / 2;

    total = total + combrep(n, n1) * combrep(m, n2);
    if(1LL * n2 * q  <= m)
      good = good + combrep(n, n1) * combrep(m - n2 * q, n2);

    //wine first
    total = total + combrep(n, n2) * combrep(m, n1);
    if(1LL * n1 * q <= m)
      good = good + combrep(n, n2) * combrep(m - n1 * q, n1);
  }

  std::cout << (good / total).number;
}