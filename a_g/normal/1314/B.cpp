#include <bits/stdc++.h>
using namespace std;

// Source: https://codeforces.com/contest/1314/submission/71830834
//
// Label the games in winners bracket from 1 to 2^n-1 so 1 is winner's finals, 2
// and 3 are semifinals, etc.
//
// Each game except for the opening games has a subtree which includes the
// subtrees of its predecessors as well as two parallel games in losers bracket.
//
// dp[x][i] is the maximum number of games covered in the subtree of game x
// under the assumption that some marked team is in game x (if i&2) and some
// marked team is in the losers bracket game after game x (if i&1).
//
// Bitwise OR works because we have two games in lower bracket and one game in
// upper bracket to cover.

const int N = 17;
const int M = 1<<N;
const int INF = 1e9;
int dp[M][4];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  int m = (1<<n)-1;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= 3; j++) {
      dp[i][j] = -INF;
    }
  }

  while (k--) {
    int a;
    cin >> a;
    int i = (m+a)/2;
    dp[i][3] = dp[i][1];
    dp[i][1] = dp[i][2] = 1;
  }

  for (int i = m/2; i >= 1; i--) {
    for (int x = 0; x < 4; x++) {
      for (int y = 0; y < 4; y++) {
        dp[i][x|y] = max(dp[i][x|y], dp[2*i][x]+dp[2*i+1][y]+(x|y));
      }
    }
  }

  cout << max({dp[1][1], dp[1][2], dp[1][3], -1})+1 << '\n';
  
}