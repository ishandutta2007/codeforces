#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
void solve() {
	int n;
	cin >> n;
	int T[n], ile[30];
	rep(i, 30) ile[i]=0;
	rep(i, n) {
		cin >> T[i];
		rep(j, 30) ile[j]+=(T[i]&(1<<j))/(1<<j);
	}
	ll ans=0;
	rep(i, 30) ans=gcd(ans, ile[i]);
	for(int i=1; i<=n; ++i) {
		if(ans%i==0) cout << i << " ";
	}
	cout << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}