#include <iostream>
#include <vector>

using namespace std;

void solve () {
  int n, m;
  cin >> n >> m;

  int cnt = 0;
  vector<vector<int>> is (n, vector<int> (m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;

      if (c == '1') {
        is[i][j] = 1;
        cnt++;
      }
    }
  }

  int mn = 3;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m; j++) {
      int cur = is[i][j] + is[i + 1][j];
      if (j != 0) {
        mn = min(mn, cur + is[i][j - 1]);
        mn = min(mn, cur + is[i + 1][j - 1]);
      }

      if (j != m - 1) {
        mn = min(mn, cur + is[i][j + 1]);
        mn = min(mn, cur + is[i + 1][j + 1]);
      }
    }
  }

  cout << cnt - max(0, mn - 1) << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}