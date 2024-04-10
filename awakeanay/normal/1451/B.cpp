#include <iostream>
#include <vector>

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, q;
    std::cin >> n >> q;
    std::string s;
    std::cin >> s;

    std::vector<std::vector<int> > left(n, std::vector<int>(2, 0)), right;
    right = left;

    for(int i = 0; i < n; i++) {
      if(i)
        for(int j = 0; j < 2; j++) {
          left[i][j] |= left[i-1][j];
          right[n-1-i][j] |= right[n-i][j];
        }

      left[i][s[i]-'0'] = 1;
      right[n-1-i][s[n-1-i]-'0'] = 1;
    }

    while(q--) {
      int l, r;
      std::cin >> l >> r;
      l--; r--;

      bool poss = false;
      if(l && left[l-1][s[l]-'0'])
        poss = true;
      if(r+1 < n && right[r+1][s[r]-'0'])
        poss = true;

      if(poss)
        std::cout << "YES";
      else
        std::cout << "NO";

      std::cout << std::endl;
    }

  }

  return 0;
}