#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const lgmax = 20;
int const nmax = 100000;
int const modulo = 1000000007;
int const inv2 = (modulo + 1) / 2;
int v[5 + nmax], pref[5 + nmax];

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

int far[1 + lgmax][1 + nmax], farp[1 + lgmax][1 + nmax];

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  int n, q;
  std::cin >> n >> q;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];

  for(int i = n; 1 <= i; i--)
    pref[i] = (v[i] + 2LL * pref[i + 1] + modulo) % modulo;
  
  for(int i = 1;i <= n; i++) {
    ll number = v[i];
    int ptr = i - 1;
    while(0 < ptr && 0 < number && number < 2 * modulo) {
      number = v[ptr] + 2 * number;
      ptr--;
    }
    if(2 * modulo <= number) {
      far[0][i] = 0;
      farp[0][i] = (modulo + pref[1] - 1LL * pref[i + 1] * lgpow(2, i) % modulo) % modulo;
    } else {
      far[0][i] = ptr;
      number = number % modulo;
      if(number < 0)
        number += modulo;
      farp[0][i] = number % modulo;
    }
  }

  for(int h = 1; h <= lgmax; h++)
    for(int i = 1; i <= n; i++) {
      far[h][i] = far[h - 1][far[h - 1][i]];
      farp[h][i] = (farp[h - 1][i] + farp[h - 1][far[h - 1][i]]) % modulo;
    }

  
  for(int i = 1;i <= q; i++) {
    int x, y;
    std::cin >> x >> y;
    int result = 0;
    for(int h = lgmax; 0 <= h; h--) {
      if(x <= far[h][y]) {
        result += farp[h][y];
        if(modulo <= result)
          result -= modulo;
        y = far[h][y];
      }
    }

    result = (modulo + result * 2LL + pref[x] - 1LL * pref[y + 1] * lgpow(2, y - x + 1) % modulo) % modulo;
    std::cout << result << '\n';
  }
  return 0;
}