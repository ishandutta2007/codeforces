#include <iostream>

#define int long long

signed main() {
  std::string s;
  std::cin >> s;

  bool poss = true;
  for(int i = 2; i < s.size(); i++) {
    if(((s[i-2]-'A') + (s[i-1]-'A'))%26 != s[i]-'A')
      poss = false;
  }

  std::cout << (poss ? "YES" : "NO") << std::endl;

  return 0;
}