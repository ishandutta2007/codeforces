#include <iostream>

signed main() {
  int n;
  std::cin >> n;

  while(n--) {
    std::string s;
    std::cin >> s;

    int sz = s.length();
    int diff = 0;
    int quest = 0;
    for(int i = 0; i < sz; i++) {
      if(s[i] == '(')
        diff++;
      else if(s[i] == ')')
        diff--;
      else
        quest++;
    }

    int open = 0;
    bool poss = true;
    for(int i = 0; i < sz; i++) {
      if(s[i] == '(')
        open++;
      else if(s[i] == ')')
        open--;
      else {
        if(quest == diff) {
          open--;
          diff--;
        }
        else {
          open++;
          diff++;
        }
        quest--;
      }

      if(open < 0)
        poss = false;
    }

    if(open != 0)
      poss = false;

    if(poss)
      std::cout << "YES";
    else
      std::cout << "NO";

    std::cout << std::endl;
  }

  return 0;
}