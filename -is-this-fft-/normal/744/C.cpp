#include <iostream>

using namespace std;

const int MAX_N = 16;
const int MAX_BAR = MAX_N * MAX_N;
const int INF = 1e9 + 5;

int rc [MAX_N];
int bc [MAX_N];
int dp [1 << MAX_N][MAX_BAR];

int main () {
  int n;
  cin >> n;

  int reds = 0, blues = 0;
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;

    if (c == 'R') reds |= 1 << i;
    else blues |= 1 << i;

    cin >> rc[i] >> bc[i];
  }

  for (int i = 0; i < 1 << n; i++) {
    for (int k = 0; k < MAX_BAR; k++) {
      dp[i][k] = -INF;
    }
  }
  
  dp[0][0] = 0;
  for (int i = 0; i < 1 << n; i++) {
    int cur_rs = __builtin_popcount(reds & i);
    int cur_bs = __builtin_popcount(blues & i);
    for (int j = 0; j < n; j++) {
      if (!(i & 1 << j)) {
        int red_bar = min(cur_rs, rc[j]);
        int blue_bar = min(cur_bs, bc[j]);

        int nxt = i | 1 << j;
        for (int k = 0; k + red_bar < MAX_BAR; k++) {
          dp[nxt][k + red_bar] = max(dp[nxt][k + red_bar], dp[i][k] + blue_bar);
        }
      }
    }
  }

  int red_sum = 0, blue_sum = 0;
  for (int i = 0; i < n; i++) {
    red_sum += rc[i];
    blue_sum += bc[i];
  }
  
  int state = (1 << n) - 1;
  int ans = max(red_sum, blue_sum);
  for (int k = 0; k < MAX_BAR; k++) {
    if (dp[state][k] >= 0) {
      ans = min(ans, max(red_sum - k, blue_sum - dp[state][k]));
    }
  }
  cout << ans + n << endl;
}