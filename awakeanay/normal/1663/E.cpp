#include <iostream>
#include <algorithm>

#define int long long

std::string win = "theseus";

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  if(n < 7) {
    std::cout << "NO" << std::endl;
    return 0;
  }
  
  std::string s[n];
  for(int i = 0; i < n; i++)
    std::cin >> s[i];

  bool poss = false;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      bool cur = true;
      for(int k = 0; k < 7; k++) {
        cur &= s[(i+k)%n][(j+k)%n] == win[k];
      }
      poss |= cur;
    }
  }

  std::cout << (poss ? "YES" : "NO") << std::endl;

  return 0;
}