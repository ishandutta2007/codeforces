#include <iostream>
#include <vector>

using ll = long long;

int main() {
  int n, m;
  std::cin >> n >> m;
  if(m < n)
    std::swap(n, m);
  if(n == 1)
    std::cout << m << '\n';
  else if(n * m <= 4)
    std::cout << n * m << '\n';
  else if(n == 2) {
    if(m % 4 == 0)
      std::cout << n * (m / 2) << '\n';
    else if(m % 4 == 1)
      std::cout << n * (m / 2) + 2 << '\n';
    else if(m % 4 == 2) 
      std::cout << n * (m / 2) + 2 << '\n';
    else if(m % 4 == 3)
      std::cout << n * (m / 2) + 2 << '\n';
  } else
    std::cout << n * m / 2 + (n * m) % 2 << '\n';
  return 0;
}