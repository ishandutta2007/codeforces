#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n, m;

vector<pii> getnbrs(int i, int j) {
  vector<pii> ret;
  if (i > 0) ret.push_back({i-1, j});
  if (i < n-1) ret.push_back({i+1, j});
  if (j > 0) ret.push_back({i, j-1});
  if (j < m-1) ret.push_back({i, j+1});
  return ret;
}


int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    vector<vector<bool>> table(n, vector<bool>(m));
    vector<vector<bool>> is_queued(n, vector<bool>(m));
    vector<vector<char>> ans(n, vector<char>(m));
    int labx, laby;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < m; j++) {
        if (s[j] == 'L') {
          labx = i;
          laby = j;
        }
        table[i][j] = (s[j] == '#');
        ans[i][j] = s[j];
      }
    }
    queue<pii> q;
    q.push({labx, laby});
    while (!q.empty()) {
      pii p = q.front();
      q.pop();
      int i = p.first;
      int j = p.second;
      ans[i][j] = '+';
      for (pii p2: getnbrs(i, j)) {
        if (ans[p2.first][p2.second] == '.' && !is_queued[p2.first][p2.second]) {
          int escapes = 0;
          for (pii p3: getnbrs(p2.first, p2.second)) {
            if (ans[p3.first][p3.second] == '.') {
              escapes++;
            }
          }
          if (escapes <= 1) {
            q.push({p2.first, p2.second});
            is_queued[p2.first][p2.second] = 1;
          }
        }
      }
    }
    ans[labx][laby] = 'L';
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << ans[i][j];
      }
      cout << '\n';
    }
  }
}