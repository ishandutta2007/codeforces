#include <iostream>
#include <vector>

#define int long long

signed main() {
  std::vector<int> isQ(10005, 0);
  for(int i = 0; i <= 100; i++)
    isQ[i*i] = 1;

  int t;
  std::cin >> t;

  while(t--) {
    int poss = 0;
    int n;
    std::cin >> n;

    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;

      poss |= !isQ[x];
    }

    std::cout << (poss ? "YES" : "NO") << std::endl;
  }

  return 0;
}