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
	string s;
	cin >> n >> k >> s;
	int mi=n, ma=-1, ans=0;
	rep(i, n-1) {
		if(s[i]=='1') ans+=10;
		if(s[i+1]=='1') ++ans;
	}
	if(!ans) {
		cout << 0 << '\n';
		return;
	}
	rep(i, n) if(s[i]=='1') {
		mi=min(mi, i);
		ma=max(ma, i);
	}
	if(mi==ma) {
		if(mi==n-1) {
			cout << ans << '\n';
			return;
		}
		if(mi==0) {
			if(n-1<=k) ans-=9;
		} else if(n-mi-1<=k) {
			ans-=10;
		} else if(mi<=k) --ans;
		cout << ans << '\n';
		return;
	}
	if(n-ma-1<=k && n-ma-1>0) {
		k-=n-ma-1;
		ans-=10;
	}
	if(mi>0 && mi<=k) --ans;
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}