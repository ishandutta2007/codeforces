#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const ll INF=1e18+7;
void solve() {
  ll n, x;
  cin >> n >> x;
  ll T[n], sum[n+1], suf[n+1], pref[n+1];
  rep(i, n) {
    cin >> T[i];
    sum[i+1]=-INF;
  }
  sum[0]=0;
  rep(i, n) {
    ll akt=0;
    for(ll j=i; j<n; ++j) {
      akt+=T[j];
      sum[j-i+1]=max(sum[j-i+1], akt);
    }
  }
  rep(i, n+1) {
    suf[i]=sum[i];
    pref[i]=sum[i]+i*x;
  }
  for(int i=n-1; i>=0; --i) suf[i]=max(suf[i], suf[i+1]);
  rep(i, n) pref[i+1]=max(pref[i+1], pref[i]);
  rep(i, n+1) cout << max(suf[i]+i*x, pref[i]) << " ";
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _=1;
  cin >> _;
  while(_--) solve();
}