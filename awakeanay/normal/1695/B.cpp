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

    int a[n];
    int best = 0;
    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
      if(a[i] < a[best])
        best = i;
    }

    if(n&1) {
      std::cout << "Mike" << std::endl;
    }
    else {
      std::cout << ((best&1) ? "Mike" : "Joe") << std::endl;
    }
  }

  return 0;
}