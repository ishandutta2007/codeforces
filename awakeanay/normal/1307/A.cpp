/*
Author: AwakeAnay
Date: 17/02/2020
Time: 21:07:16
*/

#include <iostream>

int main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, d;
    std::cin >> n >> d;

    int a[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    for(int i = 1; i < n; i++) {
      int move = std::min(d/i, a[i]);
      a[0] += move;
      d -= move*i;
    }

    std::cout << a[0] << std::endl;
  }
  return 0;
}