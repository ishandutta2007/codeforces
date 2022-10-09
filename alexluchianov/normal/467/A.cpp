#include <iostream>
#include <vector>

using ll = long long;

int main() {
  int n;
  std::cin >> n;
  int result = 0;
  for(int i = 1;i <= n; i++) {
    int a, b;
    std::cin >> a >> b;
    result += (2 <= (b - a));
  }
  std::cout << result << '\n';
  return 0;
}