#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const int N = 50;

char str[N][N];

int dp[N][N][N][N];

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> str[i][j];
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j = i; j < n; j++) {
      for (int x = n - 1; x >= 0; x--) {
        for (int y = x; y < n; y++) {
          if (i == j && x == y) {
            dp[i][j][x][y] = (str[i][x] == '#');
          } else {
            dp[i][j][x][y] = max(j - i + 1, y - x + 1);
          }
          for (int t = i; t < j; t++) {
            dp[i][j][x][y] = min(dp[i][j][x][y], dp[i][t][x][y] + dp[t + 1][j][x][y]);
          }
          for (int t = x; t < y; t++) {
            dp[i][j][x][y] = min(dp[i][j][x][y], dp[i][j][x][t] + dp[i][j][t + 1][y]);
          }
        }
      }
    }
  }
  cout << dp[0][n - 1][0][n - 1] << endl;
}