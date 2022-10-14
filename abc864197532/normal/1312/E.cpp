#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define pli pair<lli,int> 
#define X first
#define Y second
#define endl '\n'
int n;
vector <int> input;
int dp[520][520];

int solve(int i, int j) {
  if (dp[i][j] != 0) return dp[i][j];
  dp[i][j] = -1;
  fop (k,i+1,j) {
    if (solve(i, k) == solve(k, j) and dp[i][k] != -1) {
      dp[i][j] = dp[i][k] + 1;
    }
  }
  return dp[i][j];
}


int main () {
  cin >> n;
  input.resize(n);
  fop (i,0,n) cin >> input[i];
  fop (i,0,520) fop (j,0,520) dp[i][j] = 0;
  fop (i,0,n) dp[i][i+1] = input[i];
  int dp2[520];
  dp2[0] = 0;
  fop (i,1,n+1) {
    dp2[i] = 10000;
    fop (j,0,i) {
      if (solve(j, i) != -1) dp2[i] = min(dp2[i], dp2[j] + 1);
    }
  }
  cout << dp2[n] << endl;
}