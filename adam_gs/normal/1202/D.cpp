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
	ll n;
	cin >> n;
	vector<ll>V;
	while(n) {
		ll x;
		for(x=0; (x+1)*x/2<=n; ++x);
		V.pb(x);
		n-=x*(x-1)/2;
	}
	reverse(all(V));
	string ans="7";
	int akt=0;
	for(auto i : V) {
		while(akt<i) {
			ans+="3";
			++akt;
		}
		ans+="1";
	}
	reverse(all(ans));
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}