#include<bits/stdc++.h>

using namespace :: std;

#define x first
#define y second
#define SZ(x) int(x.size())
#define ll long long
#define pii pair <int, int>
#define vi vector <int>

const int MOD = 1e9+7;
int dp[2][57][57][57];

int foo(int x) {
  return (1LL<<x) % MOD;
}

int goo(int x, int y) {
  if(x == 0) return (y == 0 ? 1 : 0);
  return foo(x-1);
}

void dodaj(int &a, int b) {
  a += b;
  a %= MOD;
}

int main()
{
  ios_base::sync_with_stdio(0);
  int n, p;
  cin >> n >> p;
  vi a(n);
  for(int i=0; i<n; i++) cin >> a[i];
  dp[0][0][0][0] = 1;
  for(int i=1; i<=n; i++) {
    for(int q=0; q<2; q++) {
      for(int b=0; b<i; b++) {
        for(int c=0; b+c<i; c++) {
            if(a[i-1] != 0) {
              dodaj(dp[q][i][b][c], 1LL * dp[q][i-1][b][c] * goo(b,1) % MOD * foo(i-b-1) % MOD);
              dodaj(dp[1-q][i][b][c+1], 1LL * dp[q][i-1][b][c] * goo(b,0) % MOD * foo(i-b-1) % MOD);
            }
            if(a[i-1] != 1) {
              dodaj(dp[q][i][b][c], 1LL * dp[q][i-1][b][c] * goo(c,1) % MOD * foo(i-c-1) % MOD);
              dodaj(dp[1-q][i][b+1][c], 1LL * dp[q][i-1][b][c] * goo(c,0) % MOD * foo(i-c-1) % MOD);
            }
        }
      }
    }
  }
  int ret = 0;
  for(int i=0; i<=n; i++) {
    for(int j=0; j<=n; j++) dodaj(ret, dp[p][n][i][j]);
  }
  cout << ret << "\n";
}