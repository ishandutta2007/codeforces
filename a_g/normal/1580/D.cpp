#include <bits/stdc++.h>
using namespace std;

const int N = 4005;
long long dp[N][N];
int a[N], m;

int solve(int l, int r, int par) {
  if (l > r) return 0;
  int rt = min_element(a+l, a+r+1)-a;
  int left_root = solve(l, rt-1, rt);
  int right_root = solve(rt+1, r, rt);
  int cost = a[rt]-a[par];
  for (int i = 0; i <= rt-l; i++) {
    for (int j = 0; j <= r-rt; j++) {
      dp[rt][i+j] = max(dp[rt][i+j],
          dp[left_root][i]+dp[right_root][j]+1LL*(i+j)*(m-i-j)*cost);
      dp[rt][i+j+1] = max(dp[rt][i+j+1],
          dp[left_root][i]+dp[right_root][j]+1LL*(i+j+1)*(m-i-j-1)*cost);
    }
  }
  return rt;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  cout << dp[solve(1, n, 0)][m] << '\n';
}