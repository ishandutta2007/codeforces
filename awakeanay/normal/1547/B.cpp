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

    int apos = -1;
    int n = s.length();
    for(int i = 0; i < n; i++)
      if(s[i] == 'a')
        apos = i;

    if(apos == -1) {
      std::cout << "NO" << std::endl;
      continue;
    }

    int l = apos, r = apos;
    for(int i = 1; i < n; i++) {
      if(l+1 < n && s[l+1] == 'a' + i)
        l++;
      else if(r > 0 && s[r-1] == 'a' + i)
        r--;
    }

    if(r == 0 && l == n-1)
      std::cout << "YES" << std::endl;
    else
      std::cout << "NO" << std::endl;
  }

  return 0;
}