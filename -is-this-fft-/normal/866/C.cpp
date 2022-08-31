#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_N = 55;
const int MAX_T = 5e3 + 5;
const int ITERS = 100;

typedef long double ld;

ld P [MAX_N];
int F [MAX_N];
int S [MAX_N];
ld dp [MAX_N][MAX_T];

ld solve (int n, int R, ld X) {
  for (int t = 0; t < MAX_T; t++) {
    if (t <= R) {
      dp[n][t] = t;
    } else {
      dp[n][t] = X + t;
    }
  }

  int T = 0;
  for (int i = 0; i < n; i++) {
    T += S[i];
  }

  for (int i = n - 1; i >= 0; i--) {
    T -= S[i];
    for (int t = 0; t <= T; t++) {
      if (t != 0) {
        dp[i][t] = min(X + t,
                       P[i] * dp[i + 1][t + F[i]] +
                       (1 - P[i]) * dp[i + 1][t + S[i]]);
      } else {
        dp[i][t] = P[i] * dp[i + 1][t + F[i]] +
          (1 - P[i]) * dp[i + 1][t + S[i]];
      }
    }
  }

  return dp[0][0];
}

int main () {
  ios::sync_with_stdio(false);
  
  int n, R;
  cin >> n >> R;

  for (int i = 0; i < n; i++) {
    cin >> F[i] >> S[i] >> P[i];
    P[i] /= 100;
  }

  ld ans = 0;
  for (ld i = 1e18; i > 1e-12; i /= 2) {
    if (solve(n, R, ans + i) > ans + i) {
      ans += i;
    }
  }
  cout << fixed << setprecision(11) << ans << endl;
}