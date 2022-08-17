#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int odd = 0, even = 0;
    for(int i = 0; i < 2*n; i++) {
      int x;
      std::cin >> x;
      if(x%2)
        odd++;
      else
        even++;
    }

    if(even == odd)
      std::cout << "Yes" << std::endl;
    else
      std::cout << "No" << std::endl;
  }

  return 0;
}