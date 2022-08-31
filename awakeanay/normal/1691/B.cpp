#include <iostream>
#include <algorithm>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::pair<int, int> help[n];
    for(int i = 0; i < n; i++) {
      std::cin >> help[i].first;
      help[i].second = i;
    }

    bool poss = true;
    for(int i = 0; i < n; i++) {
      int j = i;
      while(j < n && help[j].first == help[i].first)
        j++;
      if(i == j) {
        poss = false;
        break;
      }
      std::rotate(help+i, help+i+1, help+j);
      i = j-1;
    }

    for(int i = 0; i < n; i++) {
      poss &= help[i].second != i;
    }

    if(poss) {
      for(auto j : help)
        std::cout << j.second+1 << " ";
      std::cout << std::endl;
    }
    else
      std::cout << -1 << std::endl;
  }

  return 0;
}