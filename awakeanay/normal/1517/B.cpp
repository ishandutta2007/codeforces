#include <iostream>
#include <vector>
#include <algorithm>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, m;
    std::cin >> n >> m;
    int b[n][m];

    std::pair<int, std::pair<int, int> > help[n*m];
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        std::cin >> b[i][j];
        help[i*m+j] = {b[i][j], {i, j}};
      }
    }

    std::sort(help, help+n*m);

    std::vector<std::vector<int> > mark(n, std::vector<int>(m, -1));

    for(int i = 0; i < m; i++) {
      mark[help[i].second.first][help[i].second.second] = i;
    }

    std::vector<int> ans[m];
    for(int i = 0; i < n; i++) {
      std::vector<int> proc(m, 0);
      for(int j : mark[i])
        if(j != -1)
          proc[j] = 1;

      int c = 0;
      for(int j = 0; j < m; j++) {
        if(mark[i][j] == -1) {
          while(proc[c])
            c++;
          mark[i][j] = c++;
        }
        ans[mark[i][j]].push_back(j);
      }
    }

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++)
        std::cout << b[i][ans[j][i]] << " ";
      std::cout << std::endl;
    }

  }

  return 0;
}