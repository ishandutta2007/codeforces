/*
Author: AwakeAnay
Date: 09/02/2020
Time: 20:13:42
*/

#include <iostream>

#define int long long

#define x first
#define y second

signed main() {
  std::ios::sync_with_stdio(false);
  int n;
  std::cin >> n;

  bool poss = true;
  if(n % 2)
    poss = false;

  std::pair<int, int> p[n];
  for(int i = 0; i < n; i++) {
    std::cin >> p[i].x >> p[i].y;
  }
  
  int m = n/2;
  for(int i = 0; i < n; i++) {
    int j = (i+n-1)%n;
    int k = (i+m)%n;
    int l = (i+m+n-1)%n;

    if(p[i].x + p[k].x != p[j].x + p[l].x)
      poss = false;
    if(p[i].y + p[k].y != p[j].y + p[l].y)
      poss = false;
  }

  if(poss)
    std::cout << "YES";
  else
    std::cout << "nO";

  std::cout << std::endl;
  
  return 0;
}