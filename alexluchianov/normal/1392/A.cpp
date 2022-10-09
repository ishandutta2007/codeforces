#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int solve() {
  int n;
  std::cin >> n;
  std::vector<int> v(n);
  for(int i = 0; i < n; i++)
    std::cin >> v[i];
  for(int i = 1; i < n; i++)
    if(v[i] != v[i - 1])
      return 1;
  return n;
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