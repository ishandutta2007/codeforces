#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
bool grid[N][N];
int tot = 0;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 0; i < n; i++) {
    string row;
    cin >> row;
    for (int j = 0; j < m; j++) {
      grid[i][j] = row[j] == '*';
      tot += grid[i][j];
    }
  }
  int ans = 0;
  for (int i = 0; i < tot; i++) {
    if (!grid[i%n][i/n]) ans++;
  }

  while (q--) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    if (grid[x][y]) {
      grid[x][y] = 0;
      if (n*y+x <= tot-1) ans++;
      tot--;
      if (!grid[tot%n][tot/n]) ans--;
    }
    else {
      grid[x][y] = 1;
      if (n*y+x <= tot-1) ans--;
      if (!grid[tot%n][tot/n]) ans++;
      tot++;
    }
    cout << ans << '\n';
  }
}