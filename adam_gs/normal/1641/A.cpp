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
	ll n, x, l=0;
	cin >> n >> x;
	ll T[n], odw[n];
	rep(i, n) {
		cin >> T[i];
		odw[i]=0;
	}
	sort(T, T+n);
	ll ans=0;
	rep(i, n) if(!odw[i]) {
		while(l<n && (odw[l] || T[i]*x>T[l])) ++l;
		if(l<n) {
			if(T[i]*x==T[l]) odw[l]=1;
			else ++ans;
		} else ++ans;
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}