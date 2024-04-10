#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
void solve() {
	ll n, k;
	cin >> n >> k;
	ll T[n];
	rep(i, n) cin >> T[i];
	if(k<=n) {
		ll ans=k*(k-1)/2;
		ll akt=0;
		rep(i, k) akt+=T[i];
		ll ma=akt;
		for(int i=k; i<n; ++i) {
			akt+=T[i];
			akt-=T[i-k];
			ma=max(ma, akt);
		}
		cout << ans+ma << '\n';
	} else {
		ll ans=0;
		rep(i, n) {
			ans+=T[i];
			ans+=k-1;
			--k;
		}
		cout << ans << '\n';
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}