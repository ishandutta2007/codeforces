#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=5e3+7;
int T[LIM];
void solve() {
	int n;
	cin >> n;
	rep(i, n) cin >> T[i];
	int nr=0;
	while(nr<n && T[nr]==T[0]) ++nr;
	if(nr==n) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	rep(i, n-1) {
		if(T[i+1]==T[0]) cout << i+2 << " " << nr+1 << '\n';
		else cout << i+2 << " " << 1 << '\n';
	}
}
int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}