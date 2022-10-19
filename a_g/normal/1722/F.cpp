#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < m; j++) {
        a[i][j] = s[j]=='*';
      }
    }
    bool ok = 1;
    int id = 1;
    for (int i = 0; i+1 < n; i++) {
      for (int j = 0; j+1 < m; j++) {
        int s = a[i][j]+a[i+1][j]+a[i][j+1]+a[i+1][j+1];
        if (s == 4) ok = 0;
        if (s == 3) {
          for (int k = 0; k < 2; k++) {
            for (int l = 0; l < 2; l++) {
              if (a[i+k][j+l]) b[i+k][j+l] = id;
            }
          }
          id++;
        }
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] && !b[i][j]) ok = 0;
      }
    }

    for (int i = 0; i+1 < n; i++) {
      for (int j = 0; j+1 < m; j++) {
        for (int k = 0; k < 2; k++) {
          for (int l = 0; l < 2; l++) {
            for (int p = 0; p < 2; p++) {
              for (int q = 0; q < 2; q++) {
                int u = b[i+k][j+l];
                int v = b[i+p][j+q];
                if (u > 0 && v > 0 && u != v) ok = 0;
              }
            }
          }
        }
      }
    }

    cout << (ok ? "YES" : "NO") << '\n';
  }
}