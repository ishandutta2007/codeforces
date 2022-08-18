#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 3e4 + 5;
const int MAX_K = 205;
const int TYPEC = 13;
const int INF = 1e9;

int arr [MAX_N];
int dp [MAX_N][MAX_K][TYPEC];
// dp[i][j][k] is the best score with
// - i-th position
// - j segments finished or in progress
// - type of segment k

// pair<int, int> last [MAX_N][MAX_K][TYPEC];

// types
// 0 - positive
// 1 - negative
// 2 - positive start
// 3 - negative start
// 4 - positive end
// 5 - negative end
// 6 - neutral, last positive
// 7 - neutral, last negative
// 8 - not a segment, last positive
// 9 - not a segment, last negative
// 10 - not a segment, last positive end
// 11 - not a segment, last negative end
// 12 - not a segment, no previous segments
int coef [TYPEC] = {2, -2, 1, -1, 1, -1, 0, 0, 0, 0, 0, 0, 0};

bool can_follow (int lt, int ct) {
  if (lt == ct) {
    return lt == 6 || lt == 7;
  }
  
  if (ct == 12) return false;
  
  if (lt == 12) {
    return ct == 2 || ct == 3;
  }
  if (ct == 2 || ct == 3) {
    return lt == 12;
  }
  
  if (lt == 4) {
    return ct == 10;
  }
  if (ct == 10) {
    return lt == 4;
  }

  if (lt == 5) {
    return ct == 11;
  }
  if (ct == 11) {
    return lt == 5;
  }

  if (ct <= 5) {
    return lt % 2 != ct % 2;
  } else {
    return lt % 2 == ct % 2;
  }
}

int lastj (int j, int ct) {
  if (ct <= 7) return j - 1;
  else return j;
}

vector<int> prv [TYPEC];

/*
void print_hist (int i, int j, int ct) {
  if (i == 0) return;
  cout << i << " " << j << " " << ct << endl;
  print_hist(i - 1, last[i][j][ct].first, last[i][j][ct].second);
}
*/

int main () {
  ios::sync_with_stdio(false);
  
  int n, K;
  cin >> n >> K;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= K; j++) {
      for (int k = 0; k < TYPEC; k++) {
        dp[i][j][k] = -INF;
      }
    }
  }

  for (int i = 0; i < TYPEC; i++) {
    for (int j = 0; j < TYPEC; j++) {
      if (can_follow(i, j)) {
        prv[j].push_back(i);
      }
    }
  }

  /*
  int ops = 0;
  for (int i = 0; i < TYPEC; i++) {
    ops += prv[i].size();
  }
  cout << ops << endl;
  */
  
  dp[1][1][2] = coef[2] * arr[1];
  dp[1][1][3] = coef[3] * arr[1];
  dp[1][0][12] = 0;
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j <= K; j++) {
      for (int ct = 0; ct < TYPEC; ct++) {
        // same type
        dp[i][j][ct] = dp[i - 1][j][ct];
        //  last[i][j][ct] = {j, ct};

        // other types
        for (int lt : prv[ct]) {
          int lj = lastj(j, ct);
          if (lj >= 0 && dp[i - 1][lj][lt] != -INF) {
            if (dp[i][j][ct] < dp[i - 1][lj][lt]) {
              //  last[i][j][ct] = {lj, lt};
            }
            dp[i][j][ct] = max(dp[i][j][ct], dp[i - 1][lj][lt]);
          }
        }

        if (dp[i][j][ct] != -INF) {
          dp[i][j][ct] += coef[ct] * arr[i];
        }
      }
    }
  }

  cout << max(max(dp[n][K][4], dp[n][K][5]), max(dp[n][K][10], dp[n][K][11])) << endl;
}