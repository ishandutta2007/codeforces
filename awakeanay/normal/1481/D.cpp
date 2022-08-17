#include <iostream>
#include <vector>

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int> > bicol(n, {-1, -1} );

    std::string a[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    if(m&1) {
      std::cout << "YES" << std::endl;
      for(int i = 0; i <= m; i++)
        std::cout << i%2 + 1 << " ";
      std::cout << std::endl;
      continue;
    }

    std::pair<int, int> best = {-1, -1};
    for(int i = 0; i < n; i++)
      for(int j = i+1; j < n; j++)
        if(a[i][j] == a[j][i])
          best = {i, j};

    if(best.first != -1) {
      std::cout << "YES" << std::endl;
      for(int i = 0; i <= m; i++)
        std::cout << ((i%2) ? best.first+1 : best.second+1) << " ";
      std::cout << std::endl;
      continue;
    }

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(a[i][j] == 'a')
          bicol[i].first = j+1;
        else if(a[i][j] == 'b')
          bicol[i].second = j+1;
      }
    }

    int id = -1;
    for(int i = 0; i < n; i++) {
      if(bicol[i].first != -1 && bicol[i].second != -1)
        id = i+1;
    }

    if(id == -1) {
      std::cout << "NO" << std::endl;
      continue;
    }

    std::cout << "YES" << std::endl;
    int app = m/2;
    bool change = false;
    for(int i = 0; i <= m; i++) {
      if(i == m/2)
        change = true;
      if(i%2 == (m/2)%2)
        std::cout << id << " ";
      else if(change)
        std::cout << bicol[id-1].first << " ";
      else
        std::cout << bicol[id-1].second << " ";
    }

    std::cout << std::endl;
  }

  return 0;
}