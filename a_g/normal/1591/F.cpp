#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+2;
const int MOD = 998244353;
int a[N];
int dp[N]; // dp[i] = answer for first i terms
int dp2[N]; // dp2[i] = sum from k = 0 to i-1 of (-1)^k*dp[k]
int stk[N];
int sp = 0;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;

  dp2[1] = 1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    int nsp = sp;
    while (a[stk[nsp]] >= a[i]) nsp--;
    int j = stk[nsp];
    dp[i] = ((i&1 ? 1LL : -1LL)*a[i]*(dp2[i]-dp2[j])+((i-j)&1 ? -dp[j] : dp[j])) % MOD;

    sp = nsp;
    stk[++sp] = i;
    dp2[i+1] = (dp2[i] + (i&1 ? -dp[i] : dp[i])) % MOD;
  }

  cout << (dp[n]+MOD)%MOD << '\n';
}