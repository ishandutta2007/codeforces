#include <iostream>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, k1, k2;
    int w, bl;
    std::cin >> n >> k1 >> k2;
    std::cin >> w >> bl;

    bool poss = true;
    int a = k1, b = k2;
    int c = std::max(a, b) - std::min(a, b);
    int max = std::max(a/2 + b/2, std::min(a, b) + c/2);
    poss &= max >= w;
    a = n-k1, b = n-k2;
    c = std::max(a, b) - std::min(a, b);
    max = std::max(a/2 + b/2, std::min(a, b) + c/2);
    poss &= max >= bl;

    if(poss)
      std::cout << "YES";
    else
      std::cout << "NO";

    std::cout << std::endl;
  }

  return 0;
}