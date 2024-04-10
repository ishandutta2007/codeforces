#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=2e5+7;
const ll MOD=1e9+7;
ll ile[LIM];
ll pot(ll a, ll b) {
  ll ans=1;
  while(b) {
    if(b&1) ans=(ans*a)%MOD;
    b/=2;
    a=(a*a)%MOD;
  }
  return ans;
}
void solve() {
  int n;
  cin >> n;
  while(n--) {
    int a;
    cin >> a;
    ++ile[a];
  }
  ll ans=1, dzi=1;
  rep(i, LIM) {
    ll ilo=1;
    rep(j, ile[i]+1) ilo=(ilo*ans)%MOD;
    ans=ilo;
    ll akt=1;
    rep(j, ile[i]) {
      akt=(akt*i)%MOD;
      ans=(ans*pot(akt, dzi))%MOD;
    }
    dzi=(dzi*(ile[i]+1))%(MOD-1);
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _=1;
  //cin >> _;
  while(_--) solve();
}