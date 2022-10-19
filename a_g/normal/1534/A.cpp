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
    for (string& row: grid) cin >> row;
    int k = -1;
    for (int z = 0; z < 2; z++) {
      bool good = 1;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (grid[i][j] == '.') continue;
          int u = ((i+j)&1)^(grid[i][j] == 'R');
          if (u != z) good = 0;
        }
      }
      if (good) k = z;
    }
    if (k == -1) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << (((i+j)&1)^k ? 'R' : 'W');
      }
      cout << '\n';
    }
  }
}