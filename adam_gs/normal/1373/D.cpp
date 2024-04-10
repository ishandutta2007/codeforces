#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
ll psoms(vector<ll>&V) {
	ll ans=0, akt=0;
	for(auto i : V) {
		akt=max(akt+i, 0ll);
		ans=max(ans, akt);
	}
	return ans;
}
void solve() {
	int n;
	cin >> n;
	ll T[n], ans=0;
	rep(i, n) {
		cin >> T[i];
		if(i%2==0) ans+=T[i];
	}
	vector<ll>V;
	for(int i=1; i<n; i+=2) {
		V.pb(T[i]-T[i-1]);
	}
	ll ma=psoms(V);
	V.clear();
	for(int i=1; i+1<n; i+=2) {
		V.pb(T[i]-T[i+1]);
	}
	ma=max(ma, psoms(V));
	ans+=ma;
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}