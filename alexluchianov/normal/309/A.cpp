#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>

using ll = long long;
using ld = long double;

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, l, t;
  std::cin >> n >> l >> t;
  std::vector<int> v;
  for(int i = 0; i < n; i++) {
    int val;
    std::cin >> val;
    v.push_back(val);
  }
  for(int i = 0; i < n; i++)
    v.push_back(v[i] + l);
  
  int ptr = v.size() - 1;
  int tours = 2 * t / l;
  int rest = 2 * t - tours * l;
  ld result = 0;

  for(int i = n - 1; 0 <= i; i--) {
    while(v[i] + rest < v[ptr])
      ptr--;
    result += 1LL * tours * (n - 1) + ptr - i;
  }
  std::cout << std::setprecision(9) << std::fixed << result / 4.0;
}