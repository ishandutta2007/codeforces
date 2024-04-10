#include <bits/stdc++.h>
using namespace std;

// source: https://codeforces.com/contest/1603/submission/133690185
const int N = 1e5+5;
const int K = 18;
const long long INF = 1e18;
long long dp[K][N];

int phi[N];
long long phisum[N];

long long c(int l, int r) {
	long long ans = 0;
	for (int i = l, j; i <= r; i = j+1){
		j = r/(r/i);
		ans += phisum[r/i]*max(min(j, r) - i + 1, 0);
	}
	return ans;
}

void solve(int l, int r, int k, int low, int high) {
  // solve the problem for n in [l, r], given that x_k must be in [low, high]
  // reminds me of 1601C
  if (l > r) return;
  int m = (l+r)/2;
  int pos;
  long long val = c(low+1, m);
  for (int i = low; i <= min(high, m); i++) {
    if (dp[k-1][i] + val < dp[k][m]) {
      dp[k][m] = dp[k-1][i]+val;
      pos = i;
    }
    val -= phisum[m/(i+1)];
  }
  solve(l, m-1, k, low, pos);
  solve(m+1, r, k, pos, high);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  iota(phi, phi+N, 0);
  for (int i = 1; i < N; i++) {
    for (int j = 2*i; j < N; j += i) {
      phi[j] -= phi[i];
    }
  }
  phisum[0] = 0;
  for (int i = 1; i < N; i++) {
    phisum[i] = phisum[i-1] + phi[i];
  }

  for (int i = 0; i < K; i++) {
    for (int j = 0; j < N; j++) {
      dp[i][j] = INF;
    }
  }

  dp[0][0] = 0;

  for (int k = 1; k < K; k++) {
    solve(1, N-1, k, 0, N-1);
  }

  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    cout << dp[min(k, K-1)][n] << '\n';
  }
}