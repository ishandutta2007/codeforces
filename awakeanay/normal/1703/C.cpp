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
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    for(int i = 0; i < n; i++) {
      int b;
      std::cin >> b;

      while(b--) {
        char c;
        std::cin >> c;
        if(c == 'U') {
          a[i]--;
          if(a[i] == -1)
            a[i] = 9;
        }
        else {
          a[i]++;
          if(a[i] == 10)
            a[i] = 0;
        }
      }
    }

    for(int i = 0; i < n; i++)
      std::cout << a[i] << " ";
    std::cout << std::endl;
  }

  return 0;
}