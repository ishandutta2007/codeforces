#include <iostream>
#include <vector>

#define int long long

const int DEN = 100000;
const int INF = 100000000000000000;

int ceild(int x) {
  if(x%DEN != 0) {
    x += DEN-x%DEN;
  }
  return x/DEN;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;

  std::vector<int> poss[n+1];
  for(int i = 0; i <= m; i++)
    poss[0].push_back(i==0);

  for(int i = 1; i <= n; i++) {
    poss[i] = poss[i-1];
    int t, x, y;
    std::cin >> t >> x >> y;

    if(t == 2) {
      for(int j = 0; j <= m; j++) {
        if(!poss[i-1][j])
          continue;
        int next = j;
        int count = 0;
        while(next <= m && count <= y) {
          poss[i][next] = 1;
          next *= x;
          next = ceild(next);
          if(next <= m && poss[i-1][next])
            break;
          count++;
        }
      }
    }
    else {
      x = ceild(x);
      std::vector<int> next(m+1, -INF);
      for(int j = 0; j <= m; j++) {
        if(j-x >= 0)
          next[j] = next[j-x];
        if(poss[i-1][j])
          next[j] = j;
        if(j-next[j] <= y*x)
          poss[i][j] = 1;
      }
    }

  }

  std::vector<int> answer(m+1, -1);
  for(int i = n; i > 0; i--) {
    for(int j = 1; j <= m; j++)
      if(poss[i][j])
        answer[j] = i;
  }

  for(int j = 1; j <= m; j++)
    std::cout << answer[j] << " ";
  std::cout << std::endl;

  return 0;
}