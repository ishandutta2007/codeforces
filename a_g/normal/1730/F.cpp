#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
const int K = 1<<8;
const int INF = 1e9;
int dp[N][K], p[N], inv[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < K; j++) {
      dp[i][j] = INF;
    }
  }
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    p[x] = i;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      if (p[j] > p[i]) inv[i]++;
    }
  }

  dp[0][(1<<k)-1] = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < (1<<k); j++) {
      if (dp[i][j] == INF) continue;
      for (int m = i-k; m <= i+k+1; m++) {
        // add p[m] to q
        if (m <= 0 || m > n) continue;
        if (m == i) continue;

        if (m < i) {
          int d = i-m;
          if (j&(1<<(k-d))) continue;
          int added = inv[m];
          for (int l = i-k; l < m; l++) {
            bool absent = 0;
            if (l <= 0) continue;
            if (l < i && !(j&(1<<(k-(i-l))))) absent = 1;
            if (absent && p[l] > p[m]) added--;
          }
          int newmask = j|(1<<(k-d));
          //cout << "(" << i << ' ' << j << ") to (" << i << ' ' << newmask << ") +" << added << endl;
          dp[i][newmask] = min(dp[i][newmask], dp[i][j]+added);
        }

        if (m > i) {
          int d = m-i;
          int mask = (1<<min(d, k))-1;
          if ((j&mask) != mask) continue;
          int added = inv[m];
          for (int l = i-k; l < m; l++) {
            bool absent = 0;
            if (l <= 0) continue;
            if (l < i && !(j&(1<<(k-(i-l))))) absent = 1;
            if (l > i) absent = 1;
            if (absent && p[l] > p[m]) added--;
          }
          int newmask = (j>>d);
          if (d <= k) newmask |= 1<<(k-d);
          //cout << "(" << i << ' ' << j << ") to (" << m << ' ' << newmask << ") +" << added << endl;
          dp[m][newmask] = min(dp[m][newmask], dp[i][j]+added);
        }
      }
    }
  }
  cout << dp[n][(1<<k)-1] << '\n';
}