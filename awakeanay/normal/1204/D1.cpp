#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::string s, t;
  std::cin >> s;

  int n = s.length();
  t = s;

  for(int i = 0; i < n; i++) {
    if(s[i] == '0')
      continue;

    bool poss = true;
    int ln[2];
    ln[0] = ln[1] = 0;
    int num1 = 0;
    for(int j = i+1; j < n; j++) {
      if(s[j] == '1') {
        num1++;
        ln[1] = std::max(ln[0], ln[1])+1;
      }
      else {
        ln[0]++;
      }

      int k2 = std::max(ln[0], ln[1]);
      if(num1 != k2)
        poss = false;
    }

    if(poss)
      t[i] = '0';
  }

  std::cout << t << std::endl;

  return 0;
}