#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int N = 2e5+5;
int p[N], dp[N][2];
int n;

void upd(int i) {
  if (i > n) return;
  int z0 = -INF;
  int z1 = INF;
  if (p[i] > p[i-1]) z0 = dp[i-1][0];
  if (p[i] > dp[i-1][1]) z0 = max(z0, p[i-1]);
  if (p[i] < p[i-1]) z1 = dp[i-1][1];
  if (p[i] < dp[i-1][0]) z1 = min(z1, p[i-1]);
  if (dp[i][0] == z0 && dp[i][1] == z1) return;
  dp[i][0] = z0;
  dp[i][1] = z1;
  upd(i+1);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> p[i];
  long long ans = 0;
  int r = n;
  for (int l = n; l >= 1; l--) {
    dp[l][0] = INF;
    dp[l][1] = -INF;
    upd(l+1);
    while (dp[r][0] == -INF && dp[r][1] == INF) r--;
    ans += r-l+1;
  }
  cout << ans << '\n';
}