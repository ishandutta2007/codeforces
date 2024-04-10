#include <iostream>

signed main() {
  int a, b, k;
  std::cin >> a >> b >> k;

  if(k == 0) {
    std::cout << "YES" << std::endl;
    std::cout << std::string(b, '1') << std::string(a, '0') << std::endl;
    std::cout << std::string(b, '1') << std::string(a, '0') << std::endl;
    return 0;
  }

  if(k >= a+b-1 || a == 0 || b == 1) {
    std::cout << "No" << std::endl;
    return 0;
  }

  int m = a+b;
  int x[m], y[m];

  x[m-1] = y[m-1] = 1;
  x[k] = 1;
  y[k] = 0;
  x[0] = 0;
  y[0] = 1;

  a -= 1;
  b -= 2;

  for(int i = 1; i < m; i++) {
    if(i == m-1 || i == k)
      continue;
    if(a) {
      x[i] = y[i] = 0;
      a--;
    }
    else {
      x[i] = y[i] = 1;
    }
  }

  std::cout << "Yes" << std::endl;
  for(int i = m-1; i >= 0; i--)
    std::cout << x[i];
  std::cout << std::endl;
  for(int i = m-1; i >= 0; i--)
    std::cout << y[i];
  std::cout << std::endl;

  return 0;
}