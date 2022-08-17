#include <iostream>
#include <vector>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int a, b;
    std::cin >> a >> b;

    int n = a+b;
    int x = n/2, y = n-n/2;
    std::vector<int> poss(a+b+1, 0);

    for(int i = 0; i <= x; i++) {
      if(i <= a && x-i <= b) {
        poss[x-i+(a-i)] = 1;
      }
    }
    for(int i = 0; i <= y; i++) {
      if(i <= a && y-i <= b) {
        poss[y-i+(a-i)] = 1;
      }
    }

    int count = 0;
    for(int i = 0; i < a+b+1; i++)
      count += poss[i];

    std::cout << count << std::endl;
    for(int i = 0; i < a+b+1; i++)
      if(poss[i])
        std::cout << i << " ";
    std::cout << std::endl;
  }

  return 0;
}