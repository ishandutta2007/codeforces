#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

ll solve() {
  int n;
  std::cin >> n;
  std::vector<int> v(n);
  for(int i = 0;i < n; i++)
    std::cin >> v[i];
  ll result = 0;
  for(int i = 1; i < n; i++)
    result += std::max(v[i - 1] - v[i], 0);
  return result;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    std::cout << solve() << '\n';
  return 0;
}