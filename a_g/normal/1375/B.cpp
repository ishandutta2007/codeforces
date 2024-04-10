#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> ans(n, vector<int>(m));
    bool good = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int count = 0;
        if (i) count++;
        if (i < n-1) count++;
        if (j) count++;
        if (j < m-1) count++;
        ans[i][j] = count;
        cin >> a[i][j];
        if (a[i][j] > count) good = 0;
      }
    }

    if (good) {
      cout << "YES\n";
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          cout << ans[i][j] << ' ';
        }
        cout << '\n';
      }
    }
    else cout << "NO\n";
  }
}