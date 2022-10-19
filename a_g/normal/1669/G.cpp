#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];
    vector<string> ans(n, string(m, '.'));
    for (int j = 0; j < m; j++) {
      int free = 0;
      int stones = 0;
      int pos = n-1;
      auto place = [&] () {
        for (int k = 0; k < stones; k++) {
          ans[pos-k][j] = '*';
        }
        pos -= stones;
        for (int k = 0; k < free; k++) {
          ans[pos-k][j] = '.';
        }
        pos -= free;
        free = 0;
        stones = 0;
      };
      for (int i = n-1; i >= 0; i--) {
        if (grid[i][j] == '*') stones++;
        if (grid[i][j] == '.') free++;
        if (grid[i][j] == 'o') {
          place();
          ans[pos][j] = 'o';
          pos--;
        }
      }
      place();
    }

    for (string row: ans) {
      cout << row << '\n';
    }
  }
}