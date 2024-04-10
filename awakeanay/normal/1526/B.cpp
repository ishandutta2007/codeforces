#include <iostream>

#define int long long

const int MAX = 100005;

signed main() {
  int t;
  std::cin >> t;

  int poss[MAX];
  poss[0] = 1;

  for(int i = 1; i < MAX; i++) {
    poss[i] = 0;
    if(i >= 11 && poss[i-11])
      poss[i] = 1;
    if(i >= 111 && poss[i-111])
      poss[i] = 1;
  }

  while(t--) {
    int n;
    std::cin >> n;

    if(n >= MAX || poss[n])
      std::cout << "YES" << std::endl;
    else
      std::cout << "NO" << std::endl;
  }

  return 0;
}