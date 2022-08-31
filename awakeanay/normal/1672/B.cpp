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

    int last = 0;
    bool poss = true;

    for(int i = 0; i < n; i++) {
      int j = i;
      while(j < n && s[i] == s[j])
        j++;
      j--;

      int ct = j-i+1;
      if(s[i] == 'A') {
        if(j == n-1)
          poss = false;
        last += ct;
      }
      else {
        if(i == 0)
          poss = false;
        poss &= last >= ct;
        last -= ct;
      }

      i = j;
    }

    std::cout << (poss ? "YES" : "NO") << std::endl;
  }

  return 0;
}