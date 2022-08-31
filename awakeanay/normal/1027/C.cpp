#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::map<int, int> poss;
    std::vector<int> ls;
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      poss[x]++;
      if(poss[x] == 2) {
        ls.push_back(x);
      }
      if(poss[x] == 4) {
        ls.push_back(x);
      }
    }

    std::sort(ls.begin(), ls.end());

    int minn = 4*(ls[0] + ls[1])*(ls[0] + ls[1]);
    int mind = ls[0]*ls[1];
    int x = ls[0], y = ls[1];
    int k = ls.size();
    for(int i = 1; i < k; i++) {
      int a = ls[i-1], b = ls[i];
      int curn = 4*(a+b)*(a+b);
      int curd = a*b;

      if(curn*mind <= curd*minn) {
        minn = curn;
        mind = curd;
        x = a, y = b;
      }
    }

    std::cout << x << " " << y << " " << x << " " << y << std::endl;
  }

  return 0;
}