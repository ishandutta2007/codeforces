#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int a[N];
int b[N];
bool dp[N][N*N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    int s = accumulate(a, a+n, 0) + accumulate(b, b+n, 0);
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < N*N; j++) {
        if (dp[i][j]) {
          dp[i+1][j+a[i]] = 1;
          dp[i+1][j+b[i]] = 1;
        }
      }
    }

    int best = 0;
    for (int j = 0; j < N*N; j++) {
      if (dp[n][j]&& abs(2*j-s) < abs(2*best-s)) {
        best = j;
      }
    }
    /*
    for (int i = n; i >= 1; i--) {
      if (dp[i][best].second) swap(a[i-1], b[i-1]);
      best -= a[i];
    }

    for (int i = 0; i < n; i++) {
      cout << a[i] << ' ';
    }
    cout << '\n';
    */
    //cout << best << endl;

    long long ans = best*best+(s-best)*(s-best);
    for (int i = 0; i < n; i++) {
      ans += (n-2)*a[i]*a[i];
      ans += (n-2)*b[i]*b[i];
    }

    cout << ans << '\n';

    for (int i = 0; i <= n; i++) {
      for (int j = 0; j < N*N; j++) {
        dp[i][j] = 0;
      }
    }
  }
}