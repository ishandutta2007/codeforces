#include <bits/stdc++.h>
using namespace std;

const int N = 105;
bool dp[N][N][2][2];
// (odds, evens, is Bob's turn, Alice's parity)

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  dp[0][0][0][0] = 1;
  dp[0][0][1][0] = 1;
  for (int s = 1; s < N; s++) {
    for (int x = 0; x <= s; x++) {
      int y = s-x;
      for (int bob: {0, 1}) {
        for (int parity: {0, 1}) {
          if (bob == 1) {
            dp[x][y][bob][parity] = 1;
            if (x && !dp[x-1][y][0][parity]) dp[x][y][bob][parity] = 0;
            if (y && !dp[x][y-1][0][parity]) dp[x][y][bob][parity] = 0;
          }
          else {
            if (x && dp[x-1][y][1][parity^1]) dp[x][y][bob][parity] = 1;
            if (y && dp[x][y-1][1][parity]) dp[x][y][bob][parity] = 1;
          }
        }
      }
    }
  }

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int odds = 0, evens = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x&1) odds++;
      else evens++;
    }
    cout << (dp[odds][evens][0][0] ? "Alice" : "Bob") << '\n';
  }
}