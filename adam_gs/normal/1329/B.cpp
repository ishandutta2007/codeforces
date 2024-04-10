#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
void solve() {
  ll d, m;
  cin >> d >> m;
  ll dp[30][30], ile[30];
  rep(i, 30) rep(j, 30) dp[i][j]=0;
  rep(i, 30) {
    ll p=(1ll<<(i+1))-1;
    p=min(p, d);
    p-=(1ll<<i)-1;
    p=max(p, 0ll);
    ile[i]=p%m;
    dp[0][i]=p%m;
  }
  for(int i=1; i<30; ++i) {
    for(int j=1; j<30; ++j) {
      rep(k, j) dp[i][j]=(dp[i][j]+dp[i-1][k]*ile[j])%m;
    }
  }
  ll ans=0;
  rep(i, 30) rep(j, 30) ans=(ans+dp[i][j])%m;
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _=1;
  cin >> _;
  while(_--) solve();
}