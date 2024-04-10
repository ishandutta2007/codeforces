#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> b(n, vector<int>(m)), ans(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> b[i][j];
      }
      sort(b[i].begin(), b[i].end());
    }
    for (int i = 0; i < m; i++) {
      int id = -1;
      int best = 1e9+1;
      for (int j = 0; j < n; j++) {
        if (b[j][0] < best) {
          best = b[j][0];
          id = j;
        }
      }
      for (int j = 0; j < n; j++) {
        if (j == id) {
          ans[j][i] = b[j][0];
          b[j].erase(b[j].begin());
        }
        else {
          ans[j][i] = b[j].back();
          b[j].pop_back();
        }
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << ans[i][j] << ' ';
      }
      cout << '\n';
    }
  }
}