/*
Author: AwakeAnay
Date: 09/02/2020
Time: 19:41:20
*/

#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  int a[n];
  for(int i = 0; i < n; i++)
    std::cin >> a[i];
  
  std::vector<int> best(32, -1);
  int root = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; (1 << j) <= a[i]; j++) {
      if((1 << j) & a[i]) {
        if(best[j] == -1)
          best[j] = i;
        else
          best[j] = -2;
      }
    }
  }

  for(int i = 0; i < 32; i++)
    if(best[i] >= 0)
      root = best[i];

  std::cout << a[root] << " ";
  for(int i = 0; i < n; i++) {
    if(i == root) continue;
    std::cout << a[i] << " ";
  }

  std::cout << std::endl;
  return 0;
}