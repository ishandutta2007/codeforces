#include <iostream>
#include <vector>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    std::vector<int> ct(26, 0);

    std::string s;
    std::cin >> s;

    int p;
    std::cin >> p;

    int n = s.length();
    int cur = 0;
    for(int i = 0; i < n; i++) {
      ct[s[i]-'a']++;
      cur += s[i]-'a'+1;
    }

    for(int i = 25; i >= 0; i--) {
      while(ct[i] && cur > p) {
        cur -= i+1;
        ct[i]--;
      }
    }

    for(int i = 0; i < n; i++) {
      if(ct[s[i]-'a']) {
        std::cout << s[i];
        ct[s[i]-'a']--;
      }
    }

    std::cout << "\n";
  }

  return 0;
}