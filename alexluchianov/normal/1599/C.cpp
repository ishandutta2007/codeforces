#include <iostream>
#include <vector>

using ld = long double;

ld comb(int n, int k) {
  ld result = 1;
  for(int i = n - k + 1; i <= n; i++)
    result = result * i;
  for(int i = 1;i <= k; i++)
    result = result / i;
  return result;
}

int main() {
  int n;
  ld p;
  std::cin >> n >> p;
  ld total = comb(n, 3);
  for(int i = 0;i <= n; i++) {
    ld result = comb(i, 1) * comb(n - i, 2) * (1 / 3.0 + 1/3.0 * 1/2.0) +
                comb(i, 2) * comb(n - i, 1) +
                comb(i, 3) * comb(n - i, 0);
    if(p * total <= result) {
      std::cout << i << '\n';
      return 0;
    }
  }
 
  return 0;
}