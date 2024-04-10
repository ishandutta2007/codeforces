#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    int z = -1e9-1;
    int mx, my;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> grid[i][j];
        if (grid[i][j] > z) {
          z = grid[i][j];
          mx = i;
          my = j;
        }
      }
    }
    int u = max(mx+1, n-mx);
    int v = max(my+1, m-my);
    cout << u*v << '\n';
  }
}