#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
void solve() {
	ll n, r;
	cin >> n >> r;
	ll T[n];
	rep(i, n) cin >> T[i];
	sort(T, T+n);
	ll ans=0;
	map<ll,ll>mp;
	for(int i=n-1; i>=0; --i) {
		if(mp[T[i]]) continue;
		if(T[i]-ans*r<=0) break;
		++ans;
		mp[T[i]]=1;
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}