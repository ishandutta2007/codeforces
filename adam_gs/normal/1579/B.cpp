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
	int n;
	cin >> n;
	int T[n];
	rep(i, n) cin >> T[i];
	vector<pair<pair<int,int>,int>>ans;
	rep(i, n) {
		int aktmi=T[i], ind=i;
		for(int j=i+1; j<n; ++j) {
			if(T[j]<aktmi) {
				aktmi=T[j];
				ind=j;
			}
		}
		if(ind>i) {
			ans.pb({{i+1, ind+1}, ind-i});
			for(int j=ind; j>i; --j) {
				T[j]=T[j-1];
			}
			T[i]=aktmi;
		}
	}
	cout << ans.size() << '\n';
	for(auto i : ans) cout << i.st.st << " " << i.st.nd << " " << i.nd << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}