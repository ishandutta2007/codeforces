#include <vector>
#include <iostream>

#define int long long

signed main() {
  int n, a, b;
  std::cin >> n >> a >> b;

  if(a > 1 && b > 1) {
    std::cout << "NO" <<std::endl;
    return 0;
  }
  
  if(n == 1) {
    std::cout << "YES" << std::endl;
    std::cout << 0 << std::endl;
    return 0;
  }

  int inv = 1;
  if(a > b) {
    a ^= b ^= a ^= b;
    inv = 0;
  }

  if(a == 1 && b == 1 && n <= 3) {
    std::cout << "NO" << std::endl;
    return 0;
  }

  std::vector<std::vector<int> > mat(n, std::vector<int>(n, 0));
  for(int i = 0; i < n-b; i++) {
    mat[i][i+1] = mat[i+1][i] = 1;
  }

  std::cout << "YES" << std::endl;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(i == j)
        std::cout << 0;
      else
        std::cout << (mat[i][j]^inv);
    }
    std::cout << std::endl;
  }

  return 0;
}