#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, q;
  std::cin >> n >> q;

  std::string s;
  std::cin >> s;


  int ct = 0;
  for(int i = 0; i+3 <= n; i++) {
    if(s.substr(i, 3) == "abc")
      ct++;
  }

  while(q--) {
    int x;
    char c;
    std::cin >> x >> c;
    x--;

    for(int i = x-2; i <= x; i++) {
      if(i >= 0 && i+3 <= n)
      if(s.substr(i, 3) == "abc")
        ct--;
    }

    s[x] = c;

    for(int i = x-2; i <= x; i++) {
      if(i >= 0 && i+3 <= n)
      if(s.substr(i, 3) == "abc")
        ct++;
    }

    std::cout << ct << std::endl;
  }

  return 0;
}