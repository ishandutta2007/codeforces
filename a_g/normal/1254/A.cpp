#include <bits/stdc++.h>
using namespace std;

char num_to_char(int x) {
  if (x < 26) return 'a'+x;
  else if (x < 52) return 'A'+(x-26);
  else return '0'+(x-52);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int r, c, k;
    cin >> r >> c >> k;
    vector<vector<bool>> grid(r, vector<bool>(c));
    int rice = 0;
    for (vector<bool>& row: grid) {
      string s;
      cin >> s;
      for (int i = 0; i < c; i++) {
        row[i] = s[i] == 'R';
        rice += row[i];
      }
    }

    int cur_num = 0;
    int cur_rice = 0;
    int goal = rice/k;
    vector<vector<char>> ans(r, vector<char>(c));
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        int x = i;
        int y = (i&1 ? c-1-j : j);
        if (cur_rice == goal && grid[x][y]) {
          cur_rice = 1;
          cur_num++;
          rice -= goal;
          goal = rice/(k-cur_num);
        }
        else if (grid[x][y]) {
          cur_rice++;
        }
        ans[x][y] = num_to_char(cur_num);
      }
    }
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++ ){
        cout << ans[i][j];
      }
      cout << '\n';
    }
  }
}