#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

void add(int& x, int y) {
  x += y;
  if (x > MOD) x -= MOD;
}

// 0 moves: [1, 0, 0, ...]
// 1 move: [0, 1, 1, 1, 1, ...]
// 2 moves: [0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, ...]
// multiply by x^k/(1-x^k)

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> ans(n+1);
  vector<int> dp(n+1);
  dp[0] = 1;
  int start = 0;
  for (int j = k; start <= n; start += j, j++) {
    vector<int> ndp(n+1);
    for (int l = start + j; l <= n; l++) {
      add(ndp[l], dp[l-j]);
      add(ndp[l], ndp[l-j]);
      add(ans[l], ndp[l]);
    }
    dp = ndp;
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " \n"[i==n];
  }
}