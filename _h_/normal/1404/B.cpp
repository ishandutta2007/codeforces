#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

bool solve(){ // true if Alice catches Bob
	int n, a, b, da, db;
	cin >> n >> a >> b >> da >> db;
	--a, --b;

	vector<vi> gr(n);
	rep(_,1,n){
		int u, v;
		cin >> u >> v;
		--u, --v;
		gr[u].push_back(v);
		gr[v].push_back(u);
	}
	if(db <= 2 * da) return true;

	function<void(int,vi&,int)> dfs = [&](int v, vi &res, int d){
		if(res[v] != -1) return;
		res[v] = d;
		trav(u, gr[v]) dfs(u, res, d+1);
	};
	vi d1(n, -1), d2(n, -1);
	dfs(a, d1, 0);
	if(d1[b] <= da) return true;
	int mx = 0;
	trav(x, d1) mx = max(mx, x);
	rep(i,0,n) if(d1[i] == mx){
		dfs(i, d2, 0);
		int mmx = 0;
		trav(x, d2) mmx = max(mmx, x);
		return mmx <= 2 * da;
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	rep(_,0,n) cout << (solve() ? "Alice" : "Bob") << endl;
}