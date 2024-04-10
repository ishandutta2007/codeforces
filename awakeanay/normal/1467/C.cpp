#include <algorithm>
#include <iostream>

#define int long long

signed main() {
  int n1, n2, n3;
  std::cin >> n1 >> n2 >> n3;
  int n = n1+n2+n3;

  int a[n];
  int min = 1000000000000;
  int sum = 0;
  int run = 0;
  for(int i = 0; i < n; i++) {
    std::cin >> a[i];
    run += a[i];
    sum += a[i];
    if(i == n1-1 || i == n1+n2-1 || i == n1+n2+n3-1) {
      min = std::min(run, min);
      run = 0;
    }
  }

  int min1, min2, min3;
  min1 = *std::min_element(a, a+n1);
  min2 = *std::min_element(a+n1, a+n1+n2);
  min3 = *std::min_element(a+n1+n2, a+n);

  min = std::min(min, min1 + min2 + min3 - std::max(min1, std::max(min2, min3)));

  std::cout << sum - 2*min << std::endl;

  return 0;
}