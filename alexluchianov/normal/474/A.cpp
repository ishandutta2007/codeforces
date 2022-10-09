#include <iostream>

using ll = long long;

int const nmax = 30;
std::string keyboard = "qwertyuiopasdfghjkl;zxcvbnm,./";

int main() {
  char op;
  std::string s;
  std::cin >> op >> s;
  for(int i = 0; i < s.size(); i++) {
    int pos = 0;
    for(int j = 0; j < nmax; j++)
      if(keyboard[j] == s[i])
        pos = j;
    if(op == 'R')
      std::cout << keyboard[pos - 1];
    else
      std::cout << keyboard[pos + 1];
  }
  std::cout << '\n';
  return 0;
}