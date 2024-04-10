#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using ll = long long;

int scan(int x, int y) {
  std::cout << "SCAN " << x + 1 << " " << y + 1 << '\n' << std::flush;
  int result;
  std::cin >> result;
  return result;
}

int dig(int x, int y) {
  std::cout << "DIG " << x + 1 << " " << y + 1 << '\n' << std::flush;
  int result;
  std::cin >> result;
  return result;
}

void solve() {
  int n, m;
  std::cin >> n >> m;
  int upperleft = scan(0, 0);
  int lowerleft = scan(n - 1, 0);
  int diff = upperleft - lowerleft;
  int x = 0;
  int x2 = n - 1;
  if(diff < 0)
    x2 += diff / 2;
  else
    x += diff / 2;
  int x3 = (x + x2) / 2;
  int guaranteedHole = scan(x3, 0);
  x = (upperleft - guaranteedHole) / 2;
  x2 = n - 1 - (lowerleft - guaranteedHole) / 2;
  
  int y3 = (upperleft - x - x2) / 2;
  int holeY = scan(x3, y3);
  int y = (guaranteedHole - holeY) / 2;
  int y2 = (upperleft - x - x2) - y;
  
  if(dig(x, y) == 0) {
    dig(x2, y);
    dig(x, y2);
  } else {
    dig(x2, y2);
  }
}

int main() {
  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++) {
    solve();
  }
}