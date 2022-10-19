#include <bits/stdc++.h>
using namespace std;

// source: https://codeforces.com/contest/1704/submission/166408034
const int N = 5005;
int C[N][N], pw[N][N], fact[N];
int MOD;

int add(int x, int y) {
  x += y;
  return (x >= MOD ? x-MOD : x);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n >> MOD;
  for (int i = 0; i < N; i++) {
    C[i][0] = 1;
    fact[i] = (i ? 1LL*i*fact[i-1] % MOD : 1);
    for (int j = 1; j <= i; j++) {
      C[i][j] = add(C[i-1][j-1], C[i-1][j]);
    }
    pw[i][0] = 1;
    for (int j = 1; j < N; j++) {
      pw[i][j] = 1LL*i*pw[i][j-1] % MOD;
    }
  }
  int ans = 0;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= i && i+j <= n; j++) {
      int z = 1;
      for (int c: {C[n][i], C[i][j], C[n-i][n-i-j], j, fact[n-i-1], pw[n-i][i-j], pw[n-1][j]}) {
        z = 1LL*c*z % MOD;
      }
      ans = add(ans, z);
    }
  }
  cout << ans << '\n';
}