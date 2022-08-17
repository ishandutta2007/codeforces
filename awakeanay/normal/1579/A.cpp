#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int s[3];
    s[0] = s[1] = s[2] = 0;

    std::string c;
    std::cin >> c;
    for(int i = 0; i < c.length(); i++)
      s[c[i] - 'A']++;

    std::cout << (s[0] + s[2] == s[1] ? "YES" : "NO") << std::endl;
  }

  return 0;
}