#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];
    vector<vector<bool>> vis(n, vector<bool>(m));
    vector<vector<int>> cyc(n, vector<int>(m));
    vector<vector<int>> len(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (vis[i][j]) continue;
        vector<pair<int, int>> path(1, make_pair(i, j));
        while (1) {
          int x = path.back().first;
          int y = path.back().second;
          vis[x][y] = 1;
          int nx = x;
          int ny = y;
          if (grid[x][y] == 'L') ny--;
          if (grid[x][y] == 'R') ny++;
          if (grid[x][y] == 'U') nx--;
          if (grid[x][y] == 'D') nx++;
          if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
            int z = path.size();
            for (int k = 0; k < z; k++) {
              len[path[k].first][path[k].second] = z-k;
            }
            break;
          }
          if (vis[nx][ny]) {
            int z = path.size();
            bool found = 0;
            for (int k = 0; k < z; k++) {
              if (path[k] == make_pair(nx, ny)) {
                found = 1;
                for (int j = k; j < z; j++) {
                  cyc[path[j].first][path[j].second] = z-k;
                  len[path[j].first][path[j].second] = z-k;
                }
                for (int j = 0; j < k; j++) {
                  len[path[j].first][path[j].second] = z-j;
                }
                break;
              }
            }
            if (!found) {
              for (int k = 0; k < z; k++) {
                len[path[k].first][path[k].second] = len[nx][ny] + z-k;
              }
            }
            break;
          }
          path.push_back(make_pair(nx, ny));
        }
      }
    }

    int r, c, d=0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (len[i][j] > d) {
          r = i+1;
          c = j+1;
          d = len[i][j];
        }
      }
    }
    cout << r << " " << c << " " << d << '\n';
  }
}