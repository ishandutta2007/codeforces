#include <iostream>

void solve() {
  int n;
  std::cin >> n;
  int aux;
  for(int i = 1;i <= n; i++)
    std::cin >> aux;

  std::cout << 3 * n << '\n';
  for(int i = 1;i <= n; i += 2) { 
    std::cout << 1 << " " << i << " " << i + 1 << '\n';
    std::cout << 2 << " " << i << " " << i + 1 << '\n';
    std::cout << 1 << " " << i << " " << i + 1 << '\n';
    std::cout << 1 << " " << i << " " << i + 1 << '\n';
    std::cout << 2 << " " << i << " " << i + 1 << '\n';
    std::cout << 1 << " " << i << " " << i + 1 << '\n';
  }
  std::cout << '\n';
}
int main() {
  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}