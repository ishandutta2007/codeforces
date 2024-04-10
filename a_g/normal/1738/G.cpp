#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(n));
    vector<vector<int>> ans(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (abs(i-j) >= n-k+1) ans[i][j] = 1;
      }
    }
    vector<vector<int>> pts(n);
    for (int i = 0; i < n; i++) {
      string row;
      cin >> row;
      for (int j = 0; j < n; j++) {
        a[i][j] = row[j] == '1';
        if (!a[i][j] && !ans[i][j]) pts[i].emplace_back(j);
      }
    }
    for (int i = 0; i < k-1; i++) {
      // path from (n-1-i, k-2-i) to (k-2-i, n-1-i)
      vector<pair<int, int>> path(1, make_pair(n-1-i, k-2-i));
      while (1) {
        int x, y;
        tie(x, y) = path.back();
        if (x == k-2-i) {
          while (pts[x].size() && pts[x].back() >= y) pts[x].pop_back();
          for (int j = y+1; j <= n-1-i; j++) {
            path.emplace_back(x, j);
          }
          break;
        }
        int target = y;
        if (pts[x].size() && pts[x].back() > y) target = pts[x].back();
        while (pts[x].size() && pts[x].back() >= y) pts[x].pop_back();
        for (int j = y+1; j <= target; j++) {
          path.emplace_back(x, j);
        }
        path.emplace_back(x-1, target);
      }
      for (auto& [x, y]: path) {
        ans[x][y] = 1;
      }
    }

    bool ok = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (!a[i][j] && !ans[i][j]) ok = 0;
      }
    }
    if (!ok) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << ans[i][j];
      }
      cout << '\n';
    }
  }
}