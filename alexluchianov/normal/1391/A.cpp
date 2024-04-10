#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int main() {
  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++) {
    int val;
    std::cin >> val;
    for(int j = 1;j <= val; j++)
      std::cout << j << " ";
    std::cout << '\n';
  }
  return 0;
}