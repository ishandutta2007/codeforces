#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <algorithm>

int const nmax = 100;

void solve() {
  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++) {
    int val;
    std::cin >> val;
    val = fabs(val);
    if(i % 2 == 0)
      val = -val;
    std::cout << val << " ";
  }
  std::cout << '\n';
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
}