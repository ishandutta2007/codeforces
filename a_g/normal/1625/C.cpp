#include <bits/stdc++.h>
using namespace std;

const int N = 505;
const int INF = 1e9;
int dp[N][N];
// (index of current sign, signs removed) -> minimum time
int d[N];
int a[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, l, k;
  cin >> n >> l >> k;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      dp[i][j] = INF;
    }
  }
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    cin >> d[i];
  }
  d[n] = l;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (dp[i][j] != INF) {
        for (int m = i+1; m <= n && j+m-1-i <= k; m++) {
          dp[m][j+m-i-1] = min(dp[m][j+m-i-1], dp[i][j]+a[i]*(d[m]-d[i]));
        }
      }
    }
  }
  
  cout << *min_element(dp[n], dp[n]+k+1) << '\n';
  /*
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      if (dp[i][j] != INF) {
        cout << i << " " << j << " " << dp[i][j] << '\n';
      }
    }
  }
  */

}