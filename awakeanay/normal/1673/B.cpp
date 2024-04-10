#include <iostream>
#include <vector>

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
    int dist = 0;
    std::vector<int> ct(26, 0);
    for(int i = 0; i < n; i++) {
      ct[s[i]-'a']++;
      if(ct[s[i]-'a'] == 1)
        dist++;
    }

    int great = 0;
    int more = 0;
    for(int i = 0; i < 26; i++) {
      great += ct[i] > 1;
      more |= ct[i] > 2;
    }

    if(!great) {
      std::cout << "YES" << std::endl;
      continue;
    }

    bool poss = true;
    for(int i = 0; i < n; i++) {
      poss &= s[i] == s[i%dist];
    }

    std::cout << (poss ? "YES" : "NO") << std::endl;
  }

  return 0;
}