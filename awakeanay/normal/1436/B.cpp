#include <iostream>
#include <vector>

std::vector<int> isPr(100005, true);

signed main() {
  isPr[1] = false;
  isPr[2] = true;

  for(int i = 2; i < 100005; i++) {
    if(isPr[i]) {
      for(int j = 2*i; j < 100005; j += i) {
        isPr[j] = false;
      }
    }
  }

  int t;
  std::cin >> t;

  while(t--) {
    int p = 99991;
    int n;
    std::cin >> n;

    int a = 1;
    while(true) {
      int b = p - a*(n-1);
      if(!isPr[a] && !isPr[b]) {
        for(int i = 0; i < n; i++) {
          for(int j = 0; j < n; j++) {
            if(i == j)
              std::cout << b;
            else
              std::cout << a;
            std::cout << " ";
          }
          std::cout << std::endl;
        }
        break;
      }
      a++;
    }
  }

  return 0;
}