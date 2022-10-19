#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int cost[N];
int dp[20*N];
int b[N];
int c[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  fill(cost, cost+N, N);
  cost[1] = 0;
  for (int i = 1; i < N; i++) {
    for (int x = i; x >= 1 && i+i/x < N; x--) {
      cost[i+i/x] = min(cost[i+i/x], cost[i]+1);
    }
  }

  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < n; i++) {
      int v = cost[b[i]];
      for (int j = 20*N-v-1; j >= 0; j--) {
        dp[j+v] = max(dp[j+v], dp[j] + c[i]);
      }
    }
    cout << dp[min(k, 20*N-1)] << '\n';
    fill(dp, dp+20*N, 0);
  }
}