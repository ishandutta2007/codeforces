#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string grid[2];
    cin >> grid[0] >> grid[1];
    int l = n;
    int r = 0;
    for (int i = 0; i < n; i++) {
      if (grid[0][i] == '*' || grid[1][i] == '*') {
        l = min(l, i);
        r = i;
      }
    }
    vector<pair<int, int>> dpl(n+1), dpr(n+1);
    for (int i = 0; i <= n; i++) {
      dpl[i].second = 2;
      dpr[i].second = 2;
    }
    // second = 0, 1, 2
    for (int i = l; i < n; i++) {
      dpl[i+1] = dpl[i];
      dpl[i+1].first++;
      if (grid[0][i] == '*' && grid[1][i] == '*') {
        dpl[i+1].first++;
        dpl[i+1].second = 2;
      }
      else if (grid[0][i] == '*') {
        if (dpl[i+1].second == 1) {
          dpl[i+1].second = 2;
          dpl[i+1].first++;
        }
        else if (dpl[i+1].second == 2) {
          dpl[i+1].second = 0;
        }
      }
      else if (grid[1][i] == '*') {
        if (dpl[i+1].second == 0) {
          dpl[i+1].second = 2;
          dpl[i+1].first++;
        }
        else if (dpl[i+1].second == 2) {
          dpl[i+1].second = 1;
        }
      }
    }

    for (int i = r; i >= 0; i--) {
      dpr[i] = dpr[i+1];
      dpr[i].first++;
      if (grid[0][i] == '*' && grid[1][i] == '*') {
        dpr[i].first++;
        dpr[i].second = 2;
      }
      else if (grid[0][i] == '*') {
        if (dpr[i].second == 1) {
          dpr[i].second = 2;
          dpr[i].first++;
        }
        else if (dpr[i].second == 2) {
          dpr[i].second = 0;
        }
      }
      else if (grid[1][i] == '*') {
        if (dpr[i].second == 0) {
          dpr[i].second = 2;
          dpr[i].first++;
        }
        else if (dpr[i].second == 2) {
          dpr[i].second = 1;
        }
      }

    }
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 2; j++) {
        int steps = (grid[1-j][i] == '*');
        steps += dpl[i].first + (dpl[i].second == 1-j);
        steps += dpr[i+1].first + (dpr[i+1].second == 1-j);
        ans = min(ans, steps);
      }
    }
    cout << ans << '\n';
  }
}