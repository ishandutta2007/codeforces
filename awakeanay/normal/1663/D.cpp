#include <iostream>
#include <cctype>
#include <cassert>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::string s;
  std::cin >> s;
  std::string t = s;

  int r;
  std::cin >> r;


  bool poss;

  if(s == "ABC")
    poss = 0 <= r && r <= 1999;
  else if(s == "ARC")
    poss = 0 <= r && r <= 2799;
  else if(s == "AGC")
    poss = r >= 1200;
  
  
  if(poss)
    std::cout << "YES" << std::endl;
  else
    std::cout << "NO" << std::endl;

  return 0;
}