#include <iostream>
#include <vector>

int main() {
  int t;
  std::cin >> t;
  
  while(t--) {
    int n, m, a, b;
    std::cin >> n >> m >> a >> b;

    std::vector<std::vector<int> > arr(n, std::vector<int>(m, 0));

    int cur = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < a; j++) {
        arr[i][(cur++)%m] = 1;
      }
    }

    if(n*a == m*b) {
      std::cout << "YES" << std::endl;
      for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
          std::cout << arr[i][j];
        }
        std::cout << std::endl;
      }
    }
    else
      std::cout << "NO" << std::endl;
  }

  return 0;
}