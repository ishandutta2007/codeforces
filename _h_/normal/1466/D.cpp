#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < b; ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define trav(x, v) for(auto &x : v)
#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

void solve(){
	int n;
	cin >> n;
	vi ws(n);
	trav(x, ws) cin >> x;
	vi deg(n, 0);
	rep(_,1,n){
		int u, v;
		cin >> u >> v;
		--u, --v;
		++deg[u];
		++deg[v];
	}
	ll tot = 0;
	trav(x, ws) tot += x;
	vi ls;
	rep(i,0,n) rep(_,1,deg[i]) ls.push_back(ws[i]);
	sort(all(ls));
	reverse(all(ls));
	vector<ll> ans(1, tot);
	trav(x, ls){
		tot += x;
		ans.push_back(tot);
	}
	trav(x, ans) cout << x << " ";
	cout << endl;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	rep(_,0,n){
		solve();
	}
}