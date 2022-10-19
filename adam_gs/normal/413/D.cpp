#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const ll MOD=1e9+7;
ll dp[2][1<<10][2];
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  dp[0][0][0]=1;
  int n, k;
  cin >> n >> k; --k;
  rep(i, n) {
    int a;
    cin >> a;
    rep(j, 1<<k) rep(l, 2) {
      if(a==0 || a==2) {
        dp[1][(j+1)%(1<<k)][max(l, (j+1)/(1<<k))]+=dp[0][j][l];
        dp[1][(j+1)%(1<<k)][max(l, (j+1)/(1<<k))]%=MOD;
      }
      if(a==0 || a==4) {
        if(j%2==1) dp[1][2][l]=(dp[1][2][l]+dp[0][j][l])%MOD;
        else {
          dp[1][(j+2)%(1<<k)][max(l, (j+2)/(1<<k))]+=dp[0][j][l];
          dp[1][(j+2)%(1<<k)][max(l, (j+2)/(1<<k))]%=MOD;
        }
      }
    }
    rep(j, 1<<k) rep(l, 2) {
      dp[0][j][l]=dp[1][j][l];
      dp[1][j][l]=0;
    }
  }
  ll ans=0;
  rep(i, 1<<k) ans=(ans+dp[0][i][1])%MOD;
  cout << ans << '\n';
}