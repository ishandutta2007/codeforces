#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<vector<int>> d(2, vector<int>(n));
    vector<int> all_vals;
    for (int i = 0; i < 2; i++) {
      for (int& x: d[i]) cin >> x, all_vals.push_back(x);
    }
    sort(all_vals.begin(), all_vals.end(), greater<int>());
    all_vals.resize(unique(all_vals.begin(), all_vals.end())-all_vals.begin());
    int dist = -1;
    vector<int> pos;
    auto check = [&] (int val) {
      map<int, int> a[2];
      for (int i = 0; i < 2; i++) {
        for (int x: d[i]) {
          a[i][x]++;
        }
      }
      pos.clear();
      for (int x: all_vals) {
        if (x <= val) break;
        for (int i = 0; i < 2; i++) {
          while (a[i][x] > 0 && a[1-i][x-val] > 0) {
            a[i][x]--;
            a[1-i][x-val]--;
            pos.push_back(i ? -x+val : x);
          }
        }
      }

      for (int i = 0; i < 2; i++) {
        for (auto& [x, c]: a[i]) {
          if (c < 0) return false;
          if (x > val && c > 0) return false;
        }
      }
      for (auto& [x, c]: a[0]) {
        if (a[1][val-x] != c) return false;
        while (c--) {
          pos.push_back(x);
        }
      }
      dist = val;
      return true;
    };

    for (int i = 0; i < n; i++) {
      if (check(d[0][0]+d[1][i])) break;
      if (check(abs(d[0][0]-d[1][i]))) break;
    }
    if (dist == -1) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    int offset = 0;
    for (int& x: pos) offset = max(offset, -x);
    for (int x: pos) cout << x+offset << ' ';
    cout << '\n';
    cout << offset << ' ' << dist+offset << '\n';
  }
}