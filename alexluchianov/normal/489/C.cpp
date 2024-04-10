#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100;
int v[1 + nmax], v2[1 + nmax];

int main() {
  int n, m;
  std::cin >> n >> m;
  if(0 <= m && m <= n * 9) {
    if(m == 0) {
      if(n == 1)
        std::cout << 0 << " " << 0 << '\n';
      else
        std::cout << -1 << " " << -1 << '\n';
    } else {
      int m2 = m;
      for(int i = 1;i <= n; i++) {
        v[i] = std::min(9, m);
        m -= v[i];
      }
      m = m2;
      m--;
      for(int i = n;1 <= i; i--) {
        v2[i] = std::min(9, m);
        m -= v2[i];
      }
      v2[1]++;
      for(int i = 1;i <= n; i++)
        std::cout << v2[i];
      std::cout << " ";
      for(int i = 1;i <= n; i++)
        std::cout << v[i];
      std::cout << '\n';
    }
  } else
    std::cout << -1 << " " << -1 << '\n';
  return 0;
}