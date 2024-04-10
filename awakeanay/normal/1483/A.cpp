#include <iostream>
#include <vector>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> f[m];
    std::vector<int> choose(n, 0);
    std::vector<int> choice(m, 0);
    std::pair<int, int> best = {-1, -1};
    int max = m-m/2;
    for(int i = 0; i < m; i++) {
      int k;
      std::cin >> k;

      while(k--) {
        int x;
        std::cin >> x;
        x--;
        f[i].push_back(x);
      }

      int x = f[i][0];
      choose[x]++;
      choice[i] = x;
      best = std::max({choose[x], x}, best);
    }

    if(best.first > max) {
      for(int i = 0; i < m; i++) {
        if(choice[i] == best.second && f[i].size() > 1) {
          best.first--;
          choice[i] = f[i][1];
        }
        if(best.first == max)
          break;
      }

      if(best.first > max) {
        std::cout << "NO" << std::endl;
        continue;
      }
    }

    std::cout << "YES" << std::endl;
    for(int j : choice)
      std::cout << j+1 << " ";
    std::cout << std::endl;
  }

  return 0;
}