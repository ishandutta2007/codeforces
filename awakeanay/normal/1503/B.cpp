#include <iostream>
#include <vector>

#define int long long

signed main() {
  int n;
  std::cin >> n;

  std::vector<std::pair<int, int> > types[2];

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      types[(i+j)%2].push_back({i+1, j+1});
    }
  }

  int m = n*n;
  for(int i = 0; i < m; i++) {
    int a;
    std::cin >> a;
    if(types[0].size() == 0 || types[1].size() == 0) {
      int r = types[0].size() == 0 ? 1 : 2;
      int em = types[0].size() == 0 ? 1 : 0;
      std::cout << (a == r ? 3 : r) << " " << types[em].back().first << " " << types[em].back().second << std::endl;
      types[em].pop_back();
    }
    else {
      if(a == 1) {
        std::cout << 2 << " " << types[0].back().first << " " << types[0].back().second << std::endl;
        types[0].pop_back();
      }
      else {
        std::cout << 1 << " " << types[1].back().first << " " << types[1].back().second << std::endl;
        types[1].pop_back();
      }
    }
  }

  return 0;
}