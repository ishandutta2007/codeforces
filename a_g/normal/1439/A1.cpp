#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool table[105][105];

vector<vector<int>> ops;

void operate(int a, int b, int c, int d, int e, int f) {
  ops.push_back({a, b, c, d, e ,f});
  table[a][b] = !table[a][b];
  table[c][d] = !table[c][d];
  table[e][f] = !table[e][f];
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    ops.clear();
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < m; j++) {
        table[i][j] = s[j] == '1';
      }
    }
    for (int i = n-1; i > 1; i--) {
      for (int j = 0; j < m; j++) {
        if (table[i][j]) {
          if (j) {
            operate(i, j, i-1, j, i-1, j-1);
          }
          else {
            operate(i, j, i-1, j, i-1, j+1);
          }
        }
      }
    }
    for (int j = m-1; j > 1; j--) {
      if (table[1][j]) {
        operate(1, j, 1, j-1, 0, j-1);
      }
      if (table[0][j]) {
        operate(0, j, 1, j-1, 0, j-1);
      }
    }

    bool tot = 0;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        tot ^= table[i][j];
      }
    }
    bool s[2][2];
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        s[i][j] = tot^table[i][j];
      }
    }
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        if (s[i][j]) {
          operate((i+1)%2, j, i, (j+1)%2, (i+1)%2, (j+1)%2);
        }
      }
    }
    cout << ops.size() << '\n';
    for (vector<int> op : ops) {
      for (int i: op) cout << i+1 << ' ';
      cout << '\n';
    }
  }
}