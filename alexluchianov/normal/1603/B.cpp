#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

void solve() {
  int x, y;
  std::cin >> x >> y;
  if(y < x)
    std::cout << x + y << '\n';
  else if(x == y)
    std::cout << x << '\n';
  else
    std::cout << y - (y % x) / 2 << '\n';
}

int main() {
  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++) 
    solve();
}