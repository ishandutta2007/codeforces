#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m, k;
    cin >> n >> m >> k;
    bool table[n][m];
    bool table_copy[n][m];
    for (int i = 0; i < n ; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < m; j++) {
        table[i][j] = s[j] == '*';
        table_copy[i][j] = 0;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int d = 0;
        while (d < n) {
          if (i < d) break;
          if (j < d) break;
          if (j+d > m-1) break;
          if (!table[i-d][j-d]) break;
          if (!table[i-d][j+d]) break;
          d++;
        }
        if (d > k) {
          for (int l = 0; l < d; l++) {
            table_copy[i-l][j-l] = 1;
            table_copy[i-l][j+l] = 1;
          }
        }
      }
    }
    bool good = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (table[i][j] != table_copy[i][j]) good = 0;
      }
    }
    cout << (good ? "YES\n" : "NO\n");
  }
}