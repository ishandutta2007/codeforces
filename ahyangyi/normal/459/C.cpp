#include <iostream>

int buf[1000][1000];

int main () {
  int n, k, d;

  std::cin >> n >> k >> d;
  {
      int m = n - 1;
      for (int i = 0; i < d; ++i)
          m /= k;
      if (m) {
          std::cout << -1 << std::endl;
          return 0;
      }
  }

  for (int j = 0; j < n; ++ j) {
      int m = j;
      for (int i = 0; i < d; ++i) {
          buf[i][j] = m % k;
          m /= k;
      }
  }

  for (int i = 0; i < d; ++i) {
      for (int j = 0; j < n; ++ j) {
          std::cout << buf[i][j] + 1;
          if (j < n - 1) {
              std::cout << " ";
          } else {
              std::cout << std::endl;
          }
      }
  }
  
  return 0;
}