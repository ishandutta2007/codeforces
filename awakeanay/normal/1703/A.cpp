#include <iostream>
#include <cctype>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    std::string s;
    std::cin >> s;
    for(char &c: s)
      c = tolower(c);
    std::cout << (s == "yes" ? "YES" : "NO") << std::endl;
  }

  return 0;
}