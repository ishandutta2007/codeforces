/*
Author: AwakeAnay
Date: 12/02/2020
Time: 14:24:32
*/

#include <iostream>

int main() {
  int a, b, c;
  std::cin >> a >> b >> c;
  a++; b++; c++;
  int max = 0;
  for(int i = 0; i < 3; i++) {
    int ans = i;
    a -= 1; b -= 1; c -= 1;
    ans += (a/3) + (b/3) + (c/3);
    max = std::max(ans, max);
    if(a == 0 || b == 0 || c == 0)
      break;
  }

  std::cout << max << std::endl;
  
  return 0;
}