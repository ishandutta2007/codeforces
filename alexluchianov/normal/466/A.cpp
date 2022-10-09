#include <iostream>
#include <vector>

using ll = long long;

int main() {
  int n, m, a, b;
  std::cin >> n >> m >> a >> b;
  int result = n * a;
  for(int i = 0; i * m <= n; i++)
    result = std::min(result, i * b + (n - i * m) * a);
  std::cout << std::min((n + m - 1) / m * b, result) << '\n';
  return 0;
}