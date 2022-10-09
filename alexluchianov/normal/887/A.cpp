#include <iostream>
#include <vector>
#include <cassert>

using ll = long long;

int main() {
  std::string s;
  std::cin >> s;
  bool active = false;
  int curr = 0;
  for(int i = 0; i < s.size(); i++)
    if(s[i] == '1')
      active = 1;
    else if(s[i] == '0' && active == true)
      curr++;
  if(6 <= curr)
    std::cout << "yes\n";
  else
    std::cout << "no\n";

  return 0;
}