#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<string> grid(n);
    for (string& row: grid) cin >> row;
    vector<pair<int, int>> lcoords = {{0, 1}, {1, 0}};
    vector<pair<int, int>> rcoords = {{n-2, n-1}, {n-1, n-2}};
    for (int b: {0, 1}) {
      int c = 0;
      for (pair<int, int> p: lcoords) {
        if (grid[p.first][p.second]-'0' != b) c++;
      }
      for (pair<int, int> p: rcoords) {
        if (grid[p.first][p.second]-'0' == b) c++;
      }

      if (c <= 2) {
        cout << c << '\n';
        for (pair<int, int> p: lcoords) {
          if (grid[p.first][p.second]-'0' != b) {
            cout << p.first+1 << " " << p.second+1 << '\n';
          }
        }
        for (pair<int, int> p: rcoords) {
          if (grid[p.first][p.second]-'0' == b) {
            cout << p.first+1 << " " << p.second+1 << '\n';
          }
        }
        break;
      }
    }
  }
}