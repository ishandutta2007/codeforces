#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> grid(n);
  for (string& row: grid) cin >> row;
  string inst;
  cin >> inst;

  vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
  int ans = 0;
  do {
    int x = 0;
    int y = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 'S') {
          x = i;
          y = j;
        }
      }
    }

    bool ok = 0;
    for (char c: inst) {
      int nx = x+dir[c-'0'].first;
      int ny = y+dir[c-'0'].second;
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) break;
      if (grid[nx][ny] == '#') break;
      if (grid[nx][ny] == 'E') {
        ok = 1;
        break;
      }
      x = nx;
      y = ny;
    }
    if (ok) ans++;
  } while (next_permutation(dir.begin(), dir.end()));
  cout << ans << '\n';
}