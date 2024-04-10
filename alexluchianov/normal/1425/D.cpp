#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <bitset>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

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

int const nmax = 2000;
int const modulo = 1000000007;
int v[1 + nmax][3];
int fact[1 + nmax], pre[1 + nmax];

int inv(int number) {
  int x, y;
  gcd(number, modulo, x, y);
  x %= modulo;
  if(x < 0)
    x += modulo;
  return x;
}

void computefact() {
  fact[0] = 1;
  for(int i = 1; i <= nmax; i++)
    fact[i] = 1LL * fact[i - 1] * i % modulo;
  for(int i = 0; i <= nmax; i++)
    pre[i] = inv(fact[i]);
}


ll comb(int n, int k) {
  if(0 <= k && k <= n) {
    return 1LL * fact[n] * pre[k] % modulo * pre[n - k] % modulo;
  } else
    return 0;
}

std::bitset<1 + nmax> con[1 + nmax];

int dist(int i, int j) {
  return std::max(fabs(v[i][0] - v[j][0]), fabs(v[i][1] - v[j][1]));
}

int main() {
  int n, m, r;
  std::cin >> n >> m >> r;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i][0] >> v[i][1] >> v[i][2];
  computefact();
  ll result = 0;
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= n; j++) {
      con[i][j] = (dist(i, j) <= r);
    }

  for(int i = 1; i <= n; i++){ 
    for(int j = i;j <= n; j++) {
      std::bitset<1 + nmax> common = (con[i] & con[j]);
      int a = common.count();
      int a1 = (con[i].count() - (con[i] & common).count());
      int b1 = (con[j].count() - (con[j] & common).count());
      
      ll _count = (comb(n, m) - comb(n - a, m) + (comb(n - a, m) - comb(n - a - a1, m) - comb(n - a - b1, m) + comb(n - a - a1 - b1, m))) % modulo;
      if(_count < 0)
        _count += modulo;

      ll result2 = 1LL * v[i][2] * v[j][2] % modulo * _count % modulo;
      if(i < j)
        result2 = 2 * result2 % modulo;
      result += result2;
      if(modulo <= result)
        result -= modulo;
    }
  }
  std::cout << result;
  return 0;
}