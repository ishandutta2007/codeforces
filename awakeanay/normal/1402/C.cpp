#include <iostream>

#define int long long

signed main() {
  int n;
  std::cin >> n; 

  int a[n];
  for(int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  
  if(n == 1) {
    std::cout << 1 << " " << 1 << std::endl;
    std::cout << -a[0] << std::endl;
    std::cout << 1 << " " << 1 << std::endl;
    std::cout << 0 << std::endl;
    std::cout << 1 << " " << 1 << std::endl;
    std::cout << 0 << std::endl;
    return 0;
  }

  std::cout << 1 << " " << 1 << std::endl;
  std::cout << -a[0] << std::endl;
  a[0] = 0;

  std::cout << 2 << " " << n << std::endl;
  for(int i = 1; i < n; i++) {
    std::cout << (n-1)*a[i] << " ";
    a[i]*=n;
  }
  std::cout << std::endl;

  std::cout << 1 << " " << n << std::endl;
  for(int i = 0; i < n; i++)
    std::cout << -a[i] << " ";
  std::cout << std::endl;

  return 0;
}