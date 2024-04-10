#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const ll INF=1e9+7;
void solve() {
  int n;
  cin >> n;
  ll T[n]; 
  pair<ll,ll>dp[n][2];
  rep(i, n) cin >> T[i];
  dp[0][0]={0, 0};
  dp[0][1]={INF, -INF};
  for(int i=1; i<n-1; ++i) {
    dp[i][0]=min(dp[i-1][0], dp[i-1][1]);
    ll c=0;
    if(T[i]<=max(T[i-1], T[i+1])) c=max(T[i-1], T[i+1])-T[i]+1;
    dp[i][1]={dp[i-1][0].st-1, dp[i-1][0].nd+c};
  }
  dp[n-2][0]=min(dp[n-2][0], dp[n-2][1]);
  cout << dp[n-2][0].nd << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _;
  cin >> _;
  while(_--) solve();
}