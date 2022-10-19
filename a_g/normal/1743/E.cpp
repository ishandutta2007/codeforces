#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
int p[2];
long long t[2], dp[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  for (int i: {0, 1}) cin >> p[i] >> t[i];
  int h, s;
  cin >> h >> s;
  fill(dp+1, dp+N, 1e18);
  for (int i = 1; i <= h; i++) {
    for (int k = 0; k < 2; k++) {
      for (int j = 1; j <= i; j++) {
        long long x = t[k]*j;
        if ((p[0]-s)*(x/t[0])+(p[1]-s)*(x/t[1]) >= h) {
          dp[i] = min(dp[i], x);
          break;
        }
        if (x < t[k^1]) continue;
        long long z = x/t[k^1];
        long long dmg = (j-1)*(p[k]-s)+(z-1)*(p[k^1]-s)+(p[0]+p[1]-s);
        dp[i] = min(dp[i], dp[max(0LL, i-dmg)]+x);
      }
    }
  }
  cout << dp[h] << '\n';
}