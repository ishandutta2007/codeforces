#include <iostream>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    int x = (a-b)*n;
    int y = (a+b)*n;

    bool poss = true;
    if(x > (c+d) || y < (c-d))
      poss = false;

    if(poss)
      std::cout << "Yes";
    else
      std::cout << "No";

    std::cout << std::endl;
  }

  return 0;
}