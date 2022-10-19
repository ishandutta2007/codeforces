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
	priority_queue<pair<int,int>>q;
	vector<pair<int,int>>ans;
	rep(i, n) {
		int a;
		cin >> a;
		if(a) q.push({a, i});
	}
	while(!q.empty()) {
		int p=q.top().st, i=q.top().nd; q.pop();
		if(q.empty()) break;
		int a=q.top().st, j=q.top().nd; q.pop();
		ans.pb({i, j});
		--p;
		--a;
		if(p) q.push({p, i});
		if(a) q.push({a, j});
	}
	cout << ans.size() << '\n';
	for(auto i : ans) cout << i.st+1 << " " << i.nd+1 << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}