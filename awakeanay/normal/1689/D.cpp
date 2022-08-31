#include <iostream>
#include <vector>

#define int long long

int n, m;
const int INF = 1000006;

void empty(std::vector<std::vector<int> > &a) {
  a = std::vector<std::vector<int> >(n, std::vector<int>(m, 0));
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    std::cin >> n >> m;

    std::vector<std::vector<int> > ans, cur, val;
    empty(ans);
    empty(cur);
    empty(val);

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        char c;
        std::cin >> c;
        val[i][j] = c == 'B';
      }
    }

    for(int i = n-1; i >= 0; i--) {
      for(int j = 0; j < m; j++) {
        cur[i][j] = (val[i][j] ? 0 : -INF);
        if(i+1 < n) cur[i][j] = std::max(cur[i][j], cur[i+1][j] + 1);
        if(j) cur[i][j] = std::max(cur[i][j], cur[i][j-1] + 1);
        ans[i][j] = std::max(ans[i][j], cur[i][j]);
      }
    }

    for(int i = 0; i < n; i++) {
      for(int j = m-1; j >= 0; j--) {
        cur[i][j] = (val[i][j] ? 0 : -INF);
        if(i) cur[i][j] = std::max(cur[i][j], cur[i-1][j] + 1);
        if(j+1 < m) cur[i][j] = std::max(cur[i][j], cur[i][j+1] + 1);
        ans[i][j] = std::max(ans[i][j], cur[i][j]);
      }
    }

    for(int i = n-1; i >= 0; i--) {
      for(int j = m-1; j >= 0; j--) {
        cur[i][j] = (val[i][j] ? 0 : -INF);
        if(i+1 < n) cur[i][j] = std::max(cur[i][j], cur[i+1][j] + 1);
        if(j+1 < m) cur[i][j] = std::max(cur[i][j], cur[i][j+1] + 1);
        ans[i][j] = std::max(ans[i][j], cur[i][j]);
      }
    }

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        cur[i][j] = (val[i][j] ? 0 : -INF);
        if(i) cur[i][j] = std::max(cur[i][j], cur[i-1][j] + 1);
        if(j) cur[i][j] = std::max(cur[i][j], cur[i][j-1] + 1);
        ans[i][j] = std::max(ans[i][j], cur[i][j]);
      }
    }

    std::pair<int, std::pair<int, int> > out = {n*m, {-1, -1}};
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        out = std::min(out, {ans[i][j], {i, j}});

    std::cout << out.second.first+1 << " " << out.second.second+1 << "\n";
  }

  return 0;
}