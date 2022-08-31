#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    std::string s;
    std::cin >> s;

    int n = s.length();
    int last = n;

    int ch[26];
    for(int i = 0; i < 26; i++)
      ch[i] = -1;

    for(int i = n-1; i >= 0; i--) {
      int c = s[i]-'a';
      if(ch[c] == -1) {
        last = i;
        ch[c] = 0;
      }
    }

    for(int i = last; i < n; i++)
      std::cout << s[i];
    std::cout << std::endl;
  }

  return 0;
}