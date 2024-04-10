#include <iostream>
#include <vector>

using ll = long long;

int solve() {
  int c, d;
  std::cin >> c >> d;
  if(0 == c && 0 == d)
    return 0;
  else if(1 == (c + d) % 2)
    return -1;
  else if(c == d)
    return 1;
   return 2;
}

int main() {
  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    std::cout << solve() << '\n';
  return 0;
}