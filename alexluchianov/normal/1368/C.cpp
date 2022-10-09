#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

int main() {
  int n;
  std::cin >> n;
  std::cout << 4 + n * 3 << '\n';
  std::cout << 0 << " " << 0 << '\n';
  std::cout << 0 << " " << 1 << '\n';
  std::cout << 1 << " " << 0 << '\n';
  std::cout << 1 << " " << 1 << '\n';
  for(int i = 1;i <= n; i++) {
    std::cout << 1 + i << " " << i << '\n';
    std::cout << i << " " << 1 + i << '\n';
    std::cout << 1 + i << " " << 1 + i << '\n';
  }
}