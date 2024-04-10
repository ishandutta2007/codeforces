#include <bits/stdc++.h>
using namespace std;

const vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    bool ok = 1;
    for (string& row: grid) cin >> row;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 'B') {
          for (auto& [dx, dy]: dirs) {
            int x = i+dx;
            int y = j+dy;
            if (x < 0 || x >= n || y < 0 || y >= m) continue;
            if (grid[x][y] == 'G') ok = 0;
            if (grid[x][y] != 'G' && grid[x][y] != 'B') grid[x][y] = '#';
          }
        }
      }
    }

    vector<pair<int, int>> que;
    if (grid[n-1][m-1] == '.') {
      grid[n-1][m-1] = 'X';
      que.emplace_back(n-1, m-1);
    }

    for (int z = 0; z < (int)que.size(); z++) {
      int i = que[z].first;
      int j = que[z].second;
      for (auto& [dx, dy]: dirs) {
        int x = i+dx;
        int y = j+dy;
        if (x < 0 || x >= n || y < 0 || y >= m) continue;
        if (grid[x][y] == '.' || grid[x][y] == 'G') {
          que.emplace_back(x, y);
          grid[x][y] = 'X';
        }
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 'G') ok = 0;
      }
    }
    cout << (ok ? "Yes" : "No") << '\n';
  }
}