#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  vector<pair<int, int>> order(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    order[i] = {a[i][0], i};
  }
  sort(order.begin(), order.end());
  vector<vector<int>> b(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    b[i] = a[order[i].second];
  }
  vector<vector<int>> ulmax(n, vector<int>(m));
  vector<vector<int>> dlmin(n, vector<int>(m));
  vector<vector<int>> urmin(n, vector<int>(m));
  vector<vector<int>> drmax(n, vector<int>(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i > 0 && j > 0) {
        ulmax[i][j] = max({ulmax[i-1][j], ulmax[i][j-1], b[i][j]});
      }
      else if (i > 0) {
        ulmax[i][j] = max(ulmax[i-1][j], b[i][j]);
      }
      else if (j > 0) {
        ulmax[i][j] = max(ulmax[i][j-1], b[i][j]);
      }
      else {
        ulmax[i][j] = b[i][j];
      }
    }
  }

  for (int i = n-1; i >= 0; i--) {
    for (int j = 0; j < m; j++) {
      if (i < n-1 && j > 0) {
        dlmin[i][j] = min({dlmin[i+1][j], dlmin[i][j-1], b[i][j]});
      }
      else if (i < n-1) {
        dlmin[i][j] = min(dlmin[i+1][j], b[i][j]);
      }
      else if (j > 0) {
        dlmin[i][j] = min(dlmin[i][j-1], b[i][j]);
      }
      else {
        dlmin[i][j] = b[i][j];
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = m-1; j >= 0; j--) {
      if (i > 0 && j < m-1) {
        urmin[i][j] = min({urmin[i-1][j], urmin[i][j+1], b[i][j]});
      }
      else if (i > 0) {
        urmin[i][j] = min(urmin[i-1][j], b[i][j]);
      }
      else if (j < m-1) {
        urmin[i][j] = min(urmin[i][j+1], b[i][j]);
      }
      else {
        urmin[i][j] = b[i][j];
      }
    }
  }

  for (int i = n-1; i >= 0; i--) {
    for (int j = m-1; j >= 0; j--) {
      if (i < n-1 && j < m-1) {
        drmax[i][j] = max({drmax[i+1][j], drmax[i][j+1], b[i][j]});
      }
      else if (i < n-1) {
        drmax[i][j] = max(drmax[i+1][j], b[i][j]);
      }
      else if (j < m-1) {
        drmax[i][j] = max(drmax[i][j+1], b[i][j]);
      }
      else {
        drmax[i][j] = b[i][j];
      }
    }
  }

  for (int i = 0; i < n-1; i++) {
    for (int j = 0; j < m-1; j++) {
      if (ulmax[i][j] < dlmin[i+1][j] && urmin[i][j+1] > drmax[i+1][j+1]) {
        string s(n, 'R');
        for (int k = 0; k <= i; k++) {
          s[order[k].second] = 'B';
        }
        cout << "YES" << endl;
        cout << s << " " << j+1 << endl;
        return;
      }
    }
  }
  cout << "NO" << endl;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}