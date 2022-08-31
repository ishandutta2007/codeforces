#include <iostream>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int max = 0, sum = 0;
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      max = std::max(max, x);
      sum += x;
    }
    int orig = sum;

    if(sum%(n-1) != 0) {
      sum += n-1-(sum%(n-1));
    }

    sum = std::max(sum, (n-1)*max);
    std::cout << sum-orig << std::endl;
  }
  return 0;
}