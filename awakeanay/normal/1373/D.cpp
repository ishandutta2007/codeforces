#include <iostream>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int a[n];
    int init = 0;
    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
      if(i % 2 == 0)
        init += a[i];
    }

    int max = 0;
    int min = 0;
    int cur = 0;
    for(int i = 1; i < n; i+=2) {
      cur += a[i] - a[i-1];
      max = std::max(max, cur - min);
      min = std::min(min, cur);
    }

    cur = min = 0;
    for(int i = 1; i < n-1; i+=2) {
      cur += a[i]-a[i+1];
      max = std::max(max, cur - min);
      min = std::min(min, cur);
    }

    std::cout << init + max << std::endl;
  }

  return 0;
}