#include <iostream>
#include <algorithm>

#define int long long

signed main() {
  int n, k;
  std::cin >> n >> k;

  int a[n];
  for(int i = 0; i < n; i++)
    std::cin >> a[i];

  std::sort(a, a+n);
  std::reverse(a, a+n);

  for(int i = 0; i < n; i++) {
    for(int j = i; j < n; j++) {
      std::cout << i+1 << " ";
      for(int l = 0; l < i; l++)
        std::cout << a[l] << " ";
      std::cout << a[j] << std::endl;
      k--;
      if(k == 0)
        return 0;
    }
  }

  return 0;
}