#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, m;
    std::cin >> n >> m;

    std::string s, t;
    std::cin >> s >> t;

    bool poss = true;
    for(int i = 0; i+1 < m; i++) {
      poss &= s[n-1-i] == t[m-1-i];
    }

    int zero = 0;
    int one = 0;
    for(int i = 0; i < (n-m+1); i++) {
      if(s[i] == '1')
        one = 1;
      else
        zero = 1;
    }

    if(t[0]-'0')
      poss &= one;
    else
      poss &= zero;

    std::cout << (poss ? "YES" : "NO") << std::endl;
  }

  return 0;
}