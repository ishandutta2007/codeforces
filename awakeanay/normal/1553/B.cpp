#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    std::string a, b;
    std::cin >> a >> b;

    int n = a.length();
    int m = b.length();

    bool poss = 0;
    for(int i = 0; i < n; i++) {
      for(int j = i; j < n; j++) {
        int maxl = j-i+1+j;
        if(maxl < m)
          continue;
        int c = 0;
        int cur = true;
        for(int k = i; k <= j && c < m; k++) {
          if(b[c++] != a[k])
            cur = false;
        }
        for(int k = j-1; k >= 0 && c < m; k--) {
          if(b[c++] != a[k])
            cur = false;
        }

        poss |= cur;
      }
    }

    std::cout << (poss ? "YES" : "NO") << std::endl;
  }

  return 0;
}