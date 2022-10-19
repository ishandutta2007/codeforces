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
    vector<vector<int>> sa;
    vector<int> bad;
    for (vector<int>& row: a) {
      for (int& x: row) cin >> x;
      vector<int> srow = row;
      sort(srow.begin(), srow.end());
      sa.push_back(srow);
      for (int i = 0; i < m; i++) {
        if (row[i] != srow[i]) {
          bad.push_back(i);
        }
      }
    }
    sort(bad.begin(), bad.end());
    bad.resize(unique(bad.begin(), bad.end())-bad.begin());
    int b1 = 0;
    int b2 = 0;
    if (bad.size() == 2) {
      b1 = bad[0];
      b2 = bad[1];
    }
    else if (bad.size() == 1) {
      vector<bool> good(m);
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (a[i][j] != sa[i][bad[0]] || a[i][bad[0]] != sa[i][j]) {
            good[j] = 0;
          }
        }
      }
      for (int j = 0; j < m; j++) {
        if (good[j]) {
          b1 = min(j, bad[0]);
          b2 = max(j, bad[0]);
          break;
        }
      }
    }

    bool good = 1;
    for (vector<int>& row: a) {
      swap(row[b1], row[b2]);
      if (!is_sorted(row.begin(), row.end())) good = 0;
    }
    if (!good) {
      cout << "-1\n";
    }
    else {
      cout << b1+1 << " " << b2+1 << '\n';
    }
  }
}