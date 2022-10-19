#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
void solve() {
	int n, a, b, c, ans=0;
	string s;
	cin >> n >> a >> b >> c >> s;
	string x="";
	for(auto i : s) {
		if(i=='R') {
			if(b) {
				--b;
				++ans;
				x+='P';
			} else x+='.';
		}	else if(i=='P') {
			if(c) {
				--c;
				++ans;
				x+='S';
			} else x+='.';

		} else {
			if(a) {
				--a;
				++ans;
				x+='R';
			} else x+='.';
		}
	}
	if(ans<(n+1)/2) {
		cout << "NO\n";
		return;
	}
	rep(i, n) if(x[i]=='.') {
		if(a) {
			x[i]='R';
			--a;
		} else if(b) {
			x[i]='P';
			--b;
		} else {
			x[i]='S';
		}
	}
	cout << "YES\n" << x << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}