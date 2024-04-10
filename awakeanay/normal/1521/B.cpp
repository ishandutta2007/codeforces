#include <iostream>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int a[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    std::pair<int, int> min = {a[0], 0};
    for(int i = 0; i < n; i++)
      min = std::min(min, {a[i], i});

    std::cout << n-1 << std::endl;
    for(int i = 0; i < n; i++) {
      if(i == min.second)
        continue;
      int diff = min.second > i ? min.second-i : i-min.second;
      std::cout << i+1 << " " << min.second+1 << " " << diff+min.first << " " << min.first << std::endl;
    }
  }

  return 0;
}