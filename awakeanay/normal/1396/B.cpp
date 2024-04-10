#include <iostream>
#include <algorithm>

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int sum = 0;
    int a[n];
    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
    }

    std::sort(a, a+n);

    for(int i = 0; i+1 < n; i++)
      sum += a[i];

    if(sum < a[n-1] || (sum+a[n-1])%2)
      std::cout << "T" << std::endl;
    else
      std::cout << "HL" << std::endl;
  }

  return 0;
}