#include <iostream>

#define int long long

signed main() {
  int n, k;
  std::cin >> n >> k;

  int a[n+1];
  for(int i = 0; i < n; i++)
    std::cin >> a[i+1];

  int l = 1, r = n+1;

  while(l < r) {
    int m = (l+r)/2;
    int min[n+1];

    int cur = 0;
    bool poss = false;
    min[0] = 0;
    for(int i = 1; i <= n; i++) {
      if(a[i] >= m)
        cur += 1;
      else
        cur -= 1;

      min[i] = cur;
      if(i)
        min[i] = std::min(min[i-1], min[i]);

      if(i >= k) {
        if(cur - min[i-k] > 0) { // don't be oversmart, write proper condition
          poss = true;
        }
      }
    }

    if(!poss)
      r = m;
    else
      l = m+1;
  }

  std::cout << l-1 << std::endl;

  return 0;
}