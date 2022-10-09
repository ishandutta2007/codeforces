#include <iostream>
#include <vector>
#include <cmath>

using ll = long long;

void solve() {
  int n;
  std::cin >> n;
  int val = sqrt(n / 4);
  if(4 * val * val == n) {
    std::cout << "YES\n";
    return ;
  }
  val = sqrt(n / 2);
  if(2 * val * val == n) {
    std::cout << "YES\n";
    return ;
  }
  std::cout << "NO\n";
}
int main() {
  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}