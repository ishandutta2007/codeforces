#include <iostream>
#include <algorithm>

#define int long long

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

    std::sort(a, a+n);
    if(n <= 2) {
      std::cout << a[0] << " " << a[1] << std::endl;
      continue;
    }
    int min = 10000000000;
    int max = 0;
    int x = -1;

    for(int i = 0; i+1 < n; i++) {
      int l = 0;
      while(l == i || l == i+1)
        l++;
      int r = n-1;
      while(r == i || r == i+1)
        r--;

      int cur = a[i+1]-a[i];
      int val = n;
      val -= a[n] > a[0];
      if(cur < min) {
        min = cur;
        max = val;
        x = i;
      }
      else if(cur == min && val > max) {
        max = val;
        x = i;
      }
    }

    for(int i = x+1; i < n; i++)
      std::cout << a[i] << " ";
    for(int i = 0; i <= x; i++)
      std::cout << a[i] << " ";
    std::cout << std::endl;
  }

  return 0;
}