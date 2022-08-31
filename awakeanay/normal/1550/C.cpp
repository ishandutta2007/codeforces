#include <iostream>

#define int long long

int good(int a[], int n) {
  //std::cout << n << std::endl;
  if(n == 1 || n == 2)
    return true;
  if(n == 3) {
    if(a[0] <= a[1] && a[1] <= a[2])
      return false;
    if(a[0] >= a[1] && a[1] >= a[2])
      return false;
    return true;
  }
  for(int i = 0; i < 4; i++) {
    int b[3];
    int c = 0;
    for(int j = 0; j < 4; j++) {
      if(i == j)
        continue;
      b[c++] = a[j];
    }
    if(!good(b, 3))
      return false;
  }
  return true;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n; 
    std::cin >> n;

    int a[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    int ans = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 1; j <= 4 && i-j+1 >= 0; j++) {
        ans += good(a+i-j+1, j);
      }
    }
    
    std::cout << ans << std::endl;
  }

  return 0;
}