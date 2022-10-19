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
	vector<ll>ans;
	ans.pb(1);
	rep(i, n-1) {
		ans.pb(ans.back()*3);
		if(ans.back()>1000000000) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	for(auto i : ans) cout << i << " ";
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}