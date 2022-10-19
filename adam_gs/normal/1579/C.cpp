#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	string T[n];
	int odw[n][m];
	rep(i, n) cin >> T[i];
	rep(i, n) rep(j, m) odw[i][j]=0;
	rep(i, n) {
		rep(j, m) if(T[i][j]=='*') {
			int d=0;
			while(i-d>0 && j+d<m-1 && j-d>0 && T[i-d-1][j+d+1]=='*' && T[i-d-1][j-d-1]=='*') ++d;
			if(d>=k) {
				rep(l, d+1) {
					odw[i-l][j+l]=1;
					odw[i-l][j-l]=1;
				}
			} 
		}
	}
	rep(i, n) rep(j, m) if(T[i][j]=='*' && !odw[i][j]) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
}
int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}