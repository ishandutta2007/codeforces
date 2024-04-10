#include <iostream>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::string t(n, 0);
    int j = 0;
    for(int i = 0; i < s.size(); i+=2)
      t[j++] = s[i];

    std::cout << t << std::endl;
  }

  return 0;
}