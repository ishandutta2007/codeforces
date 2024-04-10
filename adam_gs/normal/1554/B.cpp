#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define lg(a) (31-__builtin_clz(a))
#define all(a) a.begin(), a.end()
ll pow(ll a,ll b,ll c){ll w=1;while(b){if(b&1)w=(w*a)%c;b/=2;a=(a*a)%c;}return w;}
void solve() {
	ll n, k;
	cin >> n >> k;
	ll T[n];
	rep(i, n) cin >> T[i];
	ll ans=n*(n-1)-k*(T[n-1]|T[n-2]);
	for(ll i=n-1; i>=0; --i) {
		for(ll j=i-1; j>=0 && (i+1)*(j+1)>ans; --j) {
			ans=max(ans, (i+1)*(j+1)-k*(T[i]|T[j]));
		}
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t=1;
	cin >> t;
	while(t--) solve();
}