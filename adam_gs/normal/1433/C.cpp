#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=3e5+7;
int T[LIM];
void solve() {
	int n, ma=0, ile=0;
	cin >> n;
	rep(i, n) {
		cin >> T[i];
		if(T[i]>ma) {
			ma=T[i];
			ile=0;
		}
		if(T[i]==ma) ++ile;
	}
	if(ile==n) {
		cout << -1 << '\n';
		return;
	}
	rep(i, n) if(T[i]==ma) {
		if(i && T[i]>T[i-1]) {
			cout << i+1 << '\n';
			return;
		}
		if(i<n-1 && T[i]>T[i+1]) {
			cout << i+1 << '\n';
			return;
		}
	}
}
int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}