#include <bits/stdc++.h>
using namespace std;

// source: https://codeforces.com/contest/1188/submission/56600186

const int N = 1e5+5;
const int INF = 1e9;
const int bits = 62;
long long a[N];
long long parts[2][N];
int dp[bits][N];
// dp[i][j] = minimum number of operations such that the rightmost i bits all match, and the last j terms have carries on bit i+1
int b[N]; // cumulative frequency of 1

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < bits; i++) {
    for (int j = 0; j <= n; j++) {
      dp[i][j] = INF;
    }
  }

  dp[0][0] = 0;
  for (int i = 0; i < bits-1; i++) {
    int n0 = 0, n1 = 0;
    b[0] = 0;
    for (int j = 0; j < n; j++) {
      b[j+1] = b[j];
      if (a[j] & (1LL<<i)) {
        parts[1][n1++] = a[j];
        b[j+1]++;
      }
      else {
        parts[0][n0++] = a[j];
      }
    }

    for (int j = 0; j <= n; j++) {
      // make this bit all 0
      dp[i+1][j+b[n-j]] = min(dp[i+1][j+b[n-j]], dp[i][j] + b[n-j]+j-(b[n]-b[n-j]));

      // make this bit all 1
      dp[i+1][b[n]-b[n-j]] = min(dp[i+1][b[n]-b[n-j]], dp[i][j] + (n-j-b[n-j]) + (b[n]-b[n-j]));
    }


    for (int k = 0; k < n0; k++) {
      a[k] = parts[0][k];
    }
    for (int k = 0; k < n1; k++) {
      a[k+n0] = parts[1][k];
    }
  }

  cout << dp[bits-1][0] << '\n';
}