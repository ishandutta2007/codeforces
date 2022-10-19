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
	if((n+1)/2<k) {
		cout << -1 << '\n';
		return;
	}
	int ans[n][n];
	rep(i, n) rep(j, n) ans[i][j]=0;
	for(int i=0; i<n; i+=2) {
		if(k) {
			ans[i][i]=1;
			--k;
		}
	}
	rep(i, n) {
		rep(j, n) cout << (ans[i][j]?'R':'.');
		cout << '\n';
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}