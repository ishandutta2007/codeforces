#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

void solve() {
  int a, b, n;
  std::cin >> a >> b >> n;
  int steps = 0;
  while(a <= n &&  b <= n) {
    if(a < b)
      a += b;
    else
      b += a;
    steps++;
  }
  std::cout << steps << '\n';
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
}