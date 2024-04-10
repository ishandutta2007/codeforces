#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 1000000;
std::pair<std::string, int> v[1 + nmax];

int main() {
  std::ios::sync_with_stdio(0);
  int n, m;
  std::cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    std::cin >> v[i].first;
    v[i].second = i;
    for(int j = 1; j < m; j += 2)
      v[i].first[j] = 'a' + (('z' - 'a') - v[i].first[j] - 'a');
  }
  std::sort(v + 1, v + n + 1);
  for(int i = 1; i <= n; i++)
    std::cout << v[i].second << " ";
  std::cout << '\n';
  return 0;
}