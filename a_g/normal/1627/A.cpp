#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    vector<vector<int>> grid(n, vector<int>(m));
    int tot = 0;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < m; j++) {
        grid[i][j] = s[j] == 'B';
        tot += grid[i][j];
      }
    }
    if (!tot) {
      cout << "-1\n";
      continue;
    }
    int ans = 2;
    for (int i = 0; i < n; i++) {
      if (grid[i][c-1]) ans = 1;
    }
    for (int j = 0; j < m; j++) {
      if (grid[r-1][j]) ans = 1;
    }
    if (grid[r-1][c-1]) ans = 0;
    cout << ans << '\n';
  }
}