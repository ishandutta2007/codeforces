#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int grid[N][N];


int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < m; j++) {
        grid[i][j] = s[j] == '1';
      }
    }
    bool good = 1;
    for (int i = 0; i < n && good; i++) {
      for (int j = 0; j < m && good; j++) {
        if (!grid[i][j]) continue;
        int l = j;
        int r = j;
        int u = i;
        int d = i;
        while (1) {
          int up = 0;
          if (u) {
            for (int k = l; k <= r; k++) {
              if (grid[u-1][k]) {
                up++;
              }
            }
          }
          if (up > 0 && up < r-l+1) {
            good = 0;
            break;
          }
          if (up == r-l+1) {
            u--;
            continue;
          }

          int down = 0;
          if (d < n-1) {
            for (int k = l; k <= r; k++) {
              if (grid[d+1][k]) {
                down++;
              }
            }
          }
          if (down > 0 && down < r-l+1) {
            good = 0;
            break;
          }
          if (down == r-l+1) {
            d--;
            continue;
          }

          int left = 0;
          if (l) {
            for (int k = u; k <= d; k++) {
              if (grid[k][l-1]) {
                left++;
              }
            }
          }
          if (left > 0 && left < d-u+1) {
            good = 0;
            break;
          }
          if (left == d-u+1) {
            l--;
            continue;
          }

          int right = 0;
          if (r < m-1) {
            for (int k = u; k <= d; k++) {
              if (grid[k][r+1]) {
                right++;
              }
            }
          }
          if (right > 0 && right < d-u+1) {
            good = 0;
            break;
          }
          if (right == d-u+1) {
            r++;
            continue;
          }
          break;
        }

        for (int i = u; i <= d; i++) {
          for (int j = l; j <= r; j++) {
            grid[i][j] = 0;
          }
        }
      }
    }

    cout << (good ? "YES" : "NO") << '\n';
  }
}