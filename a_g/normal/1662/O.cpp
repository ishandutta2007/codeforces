#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    // r = i+0.5
    // theta = j+0.5
    set<pair<int, int>> straightwalls;
    set<pair<int, int>> circwalls;
    for (int i = 0; i < n; i++) {
      char c;
      cin >> c;
      if (c == 'C') {
        int r, t1, t2;
        cin >> r >> t1 >> t2;
        for (int i = t1; i != t2; i = (i+1)%360) {
          circwalls.emplace(r, i);
        }
      }
      else {
        int r1, r2, t;
        cin >> r1 >> r2 >> t;
        for (int i = r1; i < r2; i++) {
          straightwalls.emplace(i, t);
        }
      }
    }

    vector<vector<bool>> vis(21, vector<bool>(360));
    function<void(int, int)> dfs = [&] (int i, int j) {
      if (vis[i][j]) return;
      vis[i][j] = 1;
      // go in
      if (i > 0) {
        if (!circwalls.count(make_pair(i, j))) {
          dfs(i-1, j);
        }
      }
      // go out
      if (i < 20) {
        if (!circwalls.count(make_pair(i+1, j))) {
          dfs(i+1, j);
        }
      }

      // go clockwise
      if (!straightwalls.count(make_pair(i, (j+1)%360))) {
        dfs(i, (j+1)%360);
      }

      // go counterclockwise
      if (!straightwalls.count(make_pair(i, j))) {
        dfs(i, (j+359)%360);
      }
    };
    dfs(0, 0);
    cout << (vis[20][0] ? "YES" : "NO") << '\n';
  }
}