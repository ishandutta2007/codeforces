#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_LG = 30;

ll dp [1 + MAX_LG][2][2];

ll solve_upto (ll ar, ll br) {
  if (ar < 0 || br < 0) return 0;
  
  dp[0][0][0] = 3;
  if (ar & 1) {
    dp[0][1][0] = 3;
  } else {
    dp[0][1][0] = 2;
  }
  if (br & 1) {
    dp[0][0][1] = 3;
  } else {
    dp[0][0][1] = 2;
  }
  if (ar & 1) {
    if (br & 1) {
      dp[0][1][1] = 3;
    } else {
      dp[0][1][1] = 2;
    }
  } else {
    if (br & 1) {
      dp[0][1][1] = 2;
    } else {
      dp[0][1][1] = 1;
    }
  }
  
  for (int i = 1; i <= MAX_LG; i++) {
    dp[i][0][0] = 3 * dp[i - 1][0][0];

    if (ar & 1LL << i) {
      dp[i][1][0] = 2 * dp[i - 1][0][0] + dp[i - 1][1][0];
    } else {
      dp[i][1][0] = 2 * dp[i - 1][1][0];
    }

    if (br & 1LL << i) {
      dp[i][0][1] = 2 * dp[i - 1][0][0] + dp[i - 1][0][1];
    } else {
      dp[i][0][1] = 2 * dp[i - 1][0][1];
    }

    if (ar & 1LL << i) {
      if (br & 1LL << i) {
        dp[i][1][1] = dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][1][0];
      } else {
        dp[i][1][1] = dp[i - 1][1][1] + dp[i - 1][0][1];
      }
    } else {
      if (br & 1LL << i) {
        dp[i][1][1] = dp[i - 1][1][1] + dp[i - 1][1][0];
      } else {
        dp[i][1][1] = dp[i - 1][1][1];
      }
    }
  }

  return dp[MAX_LG][1][1];
}

void solve () {
  int l, r;
  cin >> l >> r;

  cout << solve_upto(r, r) - solve_upto(r, l - 1)
    - solve_upto(l - 1, r) + solve_upto(l - 1, l - 1) << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  
  int testc;
  cin >> testc;
  for (int i = 0; i < testc; i++) {
    solve();
  }
}