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
	ll w, h;
	cin >> w >> h;
	ll ans=0;
	rep(i, 2) {
		int k;
		cin >> k;
		ll a, b;
		cin >> a;
		while(--k) cin >> b;
		ans=max(ans, h*(b-a));
	}
	rep(i, 2) {
		int k;
		cin >> k;
		ll a, b;
		cin >> a;
		while(--k) cin >> b;
		ans=max(ans, w*(b-a));
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}