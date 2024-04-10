#include <iostream>

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    std::string s;
    std::cin >> s;
    int n = s.length();

    int c[3];
    c[0] = c[1] = c[2] = 0;

    for(int i = 0; i < n; i++) {
      c[s[i]-'A']++;
    }

    int min = 0;
    for(int i = 1; i < 3; i++)
      if(c[i] >= c[min])
        min = i;

    int neg = false, pos = false;
    int val = 0;
    for(int i = 0; i < n; i++) {
      int cur = s[i] - 'A';
      if(cur == min)
        val++;
      else
        val--;
      if(val > 0)
        pos = true;
      if(val < 0)
        neg = true;
    }

    if((pos && neg) || val != 0)
      std::cout << "NO" << std::endl;
    else
      std::cout << "YES" << std::endl;
  }

  return 0;
}