#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
const int LIM=5e3+7;
ll T[LIM], dp[2][LIM];
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  rep(i, n) cin >> T[i];
  ll akt=0;
  rep(i, m) akt+=T[i];
  vector<ll>V;
  rep(i, n-m+1) {
    V.pb(akt);
    akt-=T[i];
    akt+=T[i+m];
  }
  rep(i, k) {
    rep(j, V.size()) dp[1][j]=dp[0][j];
    rep(j, V.size()-1) dp[0][j+1]=max(dp[0][j+1], dp[0][j]);
    rep(j, V.size()) {
      ll p=0;
      if(j>=m) p=dp[0][j-m];
      dp[1][j]=max(dp[1][j], p+V[j]);
    }
    rep(j, V.size()) dp[0][j]=dp[1][j];
  }
  ll ans=0;
  rep(j, V.size()) ans=max(ans, dp[0][j]);
  cout << ans << '\n';
}