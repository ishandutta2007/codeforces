#include <iostream>

using namespace std;

const int MAX_N = 105;
const int MAX_C = 1e4 + 5;
const int INF = 1e9 + 5;

int dp [MAX_N][MAX_C]; // <# of things, sum of capacity>

int water [MAX_N];
int capac [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  int sumw = 0;
  for (int i = 0; i < n; i++) {
    cin >> capac[i] >> water[i];
    sumw += water[i];
  }

  for (int i = 0; i < MAX_N; i++) {
    for (int j = 0; j < MAX_C; j++) {
      dp[i][j] = -INF;
    }
  }
  dp[0][0] = 0;

  for (int i = 0; i < n; i++) {
    for (int j = MAX_N - 2; j >= 0; j--) {
      for (int k = 0; k + capac[i] < MAX_C; k++) {
        dp[j + 1][k + capac[i]] = max(dp[j + 1][k + capac[i]], dp[j][k] + water[i]);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    int ans = 0;
    for (int j = 0; j < MAX_C; j++) {
      ans = max(ans, min(2 * j, dp[i][j] + sumw));
    }

    int intp = ans / 2;
    int fp = (ans % 2) * 5;

    cout << intp << "." << fp << " ";
  }
  cout << '\n';
}