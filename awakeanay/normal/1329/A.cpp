#include <iostream>
#include <algorithm>

#define int long long

signed main() {
  int n, m;
  std::cin >> n >> m;

  int p[m];
  int a[m];
  int sum = 0;

  for(int i = 0; i < m; i++) {
    std::cin >> a[i];
    sum += a[i];
  }

  bool poss = sum >= n;
  
  for(int i = 0; i < m; i++) {
    if(i + a[i] > n)
      poss = false;
    p[i] = i;
  }

  if(!poss) {
    std::cout << -1 << std::endl;
    return 0;
  }
  
  int next = n;
  for(int i = m-1; i >= 0; i--) {
    if(p[i] >= next-a[i])
      break;
    p[i] = std::max(p[i], next-a[i]);
    next = p[i];
  }

  for(int i = 0; i < m; i++)
    std::cout << p[i]+1 << " ";

  return 0;
}