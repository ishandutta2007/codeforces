#include <iostream>

int main() {
  int n;
  std::cin >> n;
  std::pair<int,int> smin, smax;
  for(int i = 1; i <= n; i++) {
    int val;
    std::cin >> val;
    if(i == 1)
      smin = smax = {val, 1};
    else {
      if(val < smin.first)
        smin = {val, 1};
      else if(val == smin.first)
        smin.second++;
      if(smax.first < val)
        smax = {val, 1};
      else if(val == smax.first)
        smax.second++;
    }
  }
  if(smin.first == smax.first)
    std::cout << 0;
  else
    std::cout << n - smin.second - smax.second;
  return 0;
}