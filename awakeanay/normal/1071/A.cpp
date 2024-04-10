#include <iostream>
#include <vector>

#define int long long

signed main() {
  int a, b;
  std::cin >> a >> b;

  int l = 0, r = 1000000;
  while(l < r) {
    int m = (l+r)/2;
    if(((m*(m+1))/2) > a+b)
      r = m;
    else
      l = m+1;
  }

  std::vector<int> ansa, ansb;
  for(int i = l-1; i >= 1; i--) {
    if(a >= i) {
      ansa.push_back(i);
      a -= i;
    }
    else
      ansb.push_back(i);
  }

  std::cout << ansa.size() << std::endl;
  for(int j : ansa)
    std::cout << j << " ";
  std::cout << std::endl << ansb.size() << std::endl;
  for(int j : ansb) 
    std::cout << j << " ";
  std::cout << std::endl;

  return 0;
}