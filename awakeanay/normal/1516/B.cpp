#include <iostream>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    bool poss = false;

    int a[n];
    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
      if(i)
        a[i] ^= a[i-1];
    }

    if(a[n-1] == 0)
      poss = 1;

    for(int i = 0; i < n; i++) {
      for(int j = i+1; j < n; j++) {
        if(a[j] == 0 && a[i] == (a[n-1]^a[j]))
          poss = 1;
      }
    }

    std::cout << (poss ? "YES" : "NO") << std::endl;
  }

  return 0;
}