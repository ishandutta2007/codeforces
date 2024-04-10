#include <iostream>

using namespace std;

const int MAX_C = 3e4 + 5; 
const int MAX_D = 350;

int minj (int D) {
  int len = D, pos = D;
  while (pos < MAX_C) {
    len = max(1, len - 1);
    pos += len;
  }
  return len;
}

int arr [MAX_C];
int offs;

int _dp [MAX_C][MAX_D];
int& dp (int i, int j) {
  return _dp[i][j - offs];
}

int _ex [MAX_C][MAX_D];
int& exists (int i, int j) {
  return _ex[i][j - offs];
}

int main () {
  ios::sync_with_stdio(false);

  int n, D;
  cin >> n >> D;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    arr[x]++;
  }
  
  offs = minj(D);
  dp(D, D) = 0;
  exists(D, D) = 1;
  int ans = 0;
  for (int i = D; i < MAX_C; i++) {
    for (int j = offs; j < offs + MAX_D; j++) {
      if (exists(i, j)) {
        dp(i, j) += arr[i];
        // cout << i << " " << j << " " << dp(i, j) << endl;
        ans = max(ans, dp(i, j));
        for (int nj = j - 1; nj <= j + 1; nj++) {
          if (nj > 0 && i + nj < MAX_C) {
            dp(i + nj, nj) = max(dp(i + nj, nj), dp(i, j));
            exists(i + nj, nj) = 1;
          }
        }
      }
    }
  }
  cout << ans << endl;
}