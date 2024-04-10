#include <iostream>

#define int long long

const int MAX = 55;
bool poss[MAX];

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  poss[0] = poss[1] = poss[2] = 0;
  poss[3] = poss[4] = poss[5] = 1;

  for(int i = 6; i < MAX; i++) {
    for(int j = 0; j < 3; j++)
      poss[i] |= poss[i-j-3];
  }

  while(t--) {
    int n;
    std::cin >> n;

    n = (n+1)/2;

    while(n < MAX && poss[n] == 0)
      n++;

    std::cout << n*5 << std::endl;
  }

  return 0;
}