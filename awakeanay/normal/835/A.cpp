#include <iostream>

#define int long long

signed main() {
  int s, v1, v2, t1, t2;
  std::cin >> s >> v1 >> v2 >> t1 >> t2;

  int a = 2*t1 + s*v1;
  int b = 2*t2 + s*v2;

  if(a < b)
    std::cout << "First";
  else if(a > b)
    std::cout << "Second";
  else
    std::cout << "Friendship";

  std::cout << std::endl;
  return 0;
}