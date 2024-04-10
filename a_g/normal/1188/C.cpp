#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int N = 1005;
int n, k;

int dp[N][N], pref[N][N], a[N], l[N];

int add(int x, int y) {
  x += y;
  return (x >= MOD ? x-MOD : x);
}

int count(int x) {
  for (int i = 0; i < n+1; i++) {
    for (int j = 0; j < k+1; j++) {
      dp[i][j] = 0;
    }
  }
  l[0] = 0;
  for (int i = 1; i <= n; i++) {
    l[i] = l[i-1];
    while (a[l[i]] + x <= a[i-1]) l[i]++;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      if (j == 1) dp[i][j] = 1;
      else dp[i][j] = pref[l[i]][j-1];
      pref[i][j] = add(pref[i-1][j], dp[i][j]);
    }
  }
  return pref[n][k];
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a+n);
  int ans = 0;
  for (int x = 1; (k-1)*x <= 1e5; x++) {
    ans = add(ans, count(x));
  }
  cout << ans << '\n';
}