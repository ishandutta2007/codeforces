#include <iostream>

int main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, x;
    std::cin >> n >> x;

    int e = 0, o = 0;
    for(int i = 0; i < n; i++) {
      int y;
      std::cin >> y;
      if(y%2)
        o++;
      else
        e++;
    }

    bool poss = false;
    for(int i = 1; i <= o; i+=2) {
      if(x >= i && x-i <= e)
        poss = true;
    }

    if(poss)
      std::cout << "Yes";
    else
      std::cout << "No";

    std::cout << std::endl;
  }

  return 0;
}