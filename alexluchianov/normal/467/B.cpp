#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

int const nmax = 1000;
int v[1 + nmax];

int main() {
  int n, m, k;
  std::cin >> n >> m >> k;
  for(int i = 1;i <= m; i++) 
    std::cin >> v[i];
  int target, result = 0;
  std::cin >> target;
  for(int i = 1; i <= m; i++)
    result += (__builtin_popcount(v[i] ^ target) <= k);
  std::cout << result << '\n';
  return 0;
}