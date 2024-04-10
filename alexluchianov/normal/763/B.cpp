#include <iostream>
#include <vector>

using ll = long long;

int main() {
  int n;
  std::cin >> n;
  std::cout << "YES\n";

  for(int i = 1;i <= n; i++) {
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    x1 = x1 % 2 + 2;
    y1 = y1 % 2 + 2;

    if(x1 % 2 == 0 && y1 % 2 == 0)
      std::cout << 1 << '\n';
    else if(x1 % 2 == 1 && y1 % 2 == 0)
      std::cout << 2 << '\n';
    else if(x1 % 2 == 1 && y1 % 2 == 1)
      std::cout << 3 << '\n';
    else if(x1 % 2 == 0 && y1 % 2 == 1)
      std::cout << 4 << '\n';
  }
  return 0;
}