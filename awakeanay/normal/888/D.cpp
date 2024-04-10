#include <iostream>
#include <set>

#define int long long

signed main() {
  int de[6] = {1, 0, 1, 2, 9, 44};
  
  int n, k;
  std::cin >> n >> k;

  int choose = 0;
  
  for(int l = 0; l <= k; l++) {
    int cur = 1;
    for(int i = 0; i < l; i++)
      cur *= (n-i);
    for(int i = 1; i <= l; i++)
      cur /= i;
    cur *= de[l];
    choose += cur;
  }

  std::cout << choose << std::endl;
  return 0;
}