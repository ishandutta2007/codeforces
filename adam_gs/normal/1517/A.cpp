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
	ll n;
	cin >> n;
	ll x=2050;
	while(x<n) x*=10;
	int ans=0;
	while(n) {
		while(x<=n) { n-=x; ++ans; }
		x/=10;
		if(x<2050 && n) {
			cout << -1 << '\n';
			return;
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