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
	int n, k;
	cin >> n >> k;
	int T[n];
	rep(i, n) cin >> T[i];
	for(int i=30; i>=0; --i) {
		int ile=0;
		rep(j, n) if(!(T[j]&(1<<i))) ++ile;
		if(ile<=k) {
			k-=ile;
			rep(j, n) T[j]|=1<<i;
		}
	}
	int ans=T[0];
	rep(i, n) ans&=T[i];
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}