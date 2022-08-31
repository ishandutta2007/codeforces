#include <iostream>
#include <cmath>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int d, k;
    std::cin >> d >> k;

    double dl = d;
    dl *= dl;
    dl /= 2.000000;
    dl = sqrt(dl);
    
    int lim = floor(dl);
    int cur = lim/k;
        
    if((cur+1)*k*k*(cur+1) + cur*cur*k*k <= d*d)
      std::cout << "Ashish";
    else
      std::cout << "Utkarsh";

    std::cout << std::endl;
  }
  
  return 0;
}