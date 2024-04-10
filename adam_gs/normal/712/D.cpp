#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const ll MOD=1e9+7;
const int LIM=2e5+127;
int dp[2*LIM][207];
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int a, b, k, t;
  cin >> a >> b >> k >> t; t*=2;
  a-=b;
  dp[a+LIM][0]=1;
  int mi=a+LIM, ma=a+LIM;
  rep(i, t) {
    mi-=k; ma+=k;
    mi=max(mi, 0); ma=min(ma, 2*LIM-1);
    ll sum=0;
    for(int j=max(mi-k, 0); j<mi+k; ++j) {
      sum+=dp[j][i];
      if(sum>MOD) sum-=MOD;
    }
    for(int j=mi; j<=ma; ++j) {
      if(j+k<2*LIM) sum+=dp[j+k][i];
      if(sum>MOD) sum-=MOD;
      if(j-k-1>=0) sum-=dp[j-k-1][i];
      if(sum<0) sum+=MOD;
      dp[j][i+1]=sum;
    }
  }
  ll ans=0;
  for(int i=LIM+1; i<2*LIM; ++i) ans=(ans+dp[i][t])%MOD;
  cout << ans << '\n';
}