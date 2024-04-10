#include <iostream>

#define int long long 

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int min = 2*3 + 2*5 + 2*7;
    if(n <= min)
      std::cout << "NO" << std::endl;
    else 
      std::cout << "YES" << std::endl;
    
    if(n == 36)
      std::cout << "6 10 15 5" << std::endl;
    else if(n == 44)
      std::cout << "6 10 15 13" << std::endl;
    else if(n == 40)
      std::cout << "6 10 15 9" << std::endl;
    else if(n > min)
      std::cout << "6 10 14 " << n-min << std::endl;
    
  }

  return 0;
}