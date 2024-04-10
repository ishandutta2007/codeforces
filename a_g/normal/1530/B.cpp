#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int h, w;
    cin >> h >> w;
    vector<vector<bool>> table(h, vector<bool>(w));
    for (int i = 0; i < w; i += 2) {
      table[0][i] = 1;
      table[h-1][i] = 1;
    }
    for (int i = 2; i < h-2; i += 2) {
      table[i][0] = 1;
      table[i][w-1] = 1;
    }
    for (vector<bool> row: table) {
      for (bool x: row) cout << x;
      cout << '\n';
    }
  }
}