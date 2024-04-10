#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int& x: a) cin >> x;
    for (int& x: b) cin >> x;
    if (a[0] != b[0] || a[n-1] != b[n-1]) {
      cout << "NO\n";
      continue;
    }

    vector<vector<int>> c(n, vector<int>(n));
    for (int i = 0; i < n-1; i++) {
      c[min(a[i], a[i+1])-1][max(a[i], a[i+1])-1]++;
      c[min(b[i], b[i+1])-1][max(b[i], b[i+1])-1]--;
    }
    bool good = 1;
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        if (c[i][j]) good = 0;
      }
    }
    if (!good) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";

    vector<pair<int, int>> ops;

    auto operate = [&] (int l, int r) {
      assert(a[l] == a[r]);
      ops.emplace_back(l+1, r+1);
      reverse(a.begin()+l, a.begin()+r+1);
    };

    function<void(int)> solve = [&] (int i) {
      if (a[i] == b[i]) return;
      for (int j = i+1; j < n; j++) {
        if (a[j] == a[i-1] && a[j-1] == b[i]) {
          operate(i-1, j);
          return;
        }
      }
      for (int j = i; j+1 < n; j++) {
        if (a[j] == a[i-1] && a[j+1] == b[i]) {
          for (int l = i-1; l <= j; l++) {
            for (int r = j+1; r < n; r++) {
              if (a[l] == a[r]) {
                operate(l, r);
                solve(i);
                return;
              }
            }
          }
        }
      }
      assert(0);
    };

    for (int i = 0; i < n; i++) {
      solve(i);
    }

    cout << ops.size() << '\n';
    for (pair<int, int>& op: ops) {
      cout << op.first << " " << op.second << '\n';
    }
  }
}