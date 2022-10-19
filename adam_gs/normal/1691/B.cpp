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
	int n;
	cin >> n;
	int T[n];
	rep(i, n) cin >> T[i];
	int l=0;
	vector<int>ans;
	rep(i, n) {
		while(l<n && T[l]==T[i]) ++l;
		if(l==i+1) {
			cout << -1 << '\n';
			return;
		}
		for(int j=i+1; j<l; ++j) ans.pb(j);
		ans.pb(i);
		i=l-1;
	}
	for(auto i : ans) cout << i+1 << " ";
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}