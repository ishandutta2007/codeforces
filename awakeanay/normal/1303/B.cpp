/*
Author: AwakeAnay
Date: 12/02/2020
Time: 20:12:27
*/

#include <iostream>

int main() {
  int t;
  std::cin >> t;

  while(t--) {
    long long n, g, b;
    std::cin >> n >> g >> b;
    
    long long m = (n/2) + (n%2);
    long long x = (m/g) + (m%g != 0);
    std::cout << std::max((x-1)*b + m, n);
    std::cout << std::endl;
  }

  return 0;
}