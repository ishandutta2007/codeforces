// written by aitch
// on 2019 10/24 at 11:58:39
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;

ll solve(){
	int n, k;
	cin >> n >> k;

	vector<vector<pii>> gr(n);
	rep(_,1,n){
		int u, v, w;
		cin >> u >> v >> w;
		--u, --v;
		gr[u].emplace_back(v,w);
		gr[v].emplace_back(u,w);
	}
	ll ans = 0;
	function<int(int,int)> marg = [&](int v, int p){
		vector<int> ls;
		trav(e, gr[v]){
			int u = e.first, w = e.second;
			if(u == p) continue;
			int res = marg(u,v);
			res += w;
			if(res > 0) ls.push_back(res);
		}
		sort(all(ls));
		reverse(all(ls));
		rep(i,0,min(k, sz(ls))) ans += ls[i];
		if(sz(ls) >= k) return -ls[k-1];
		else return 0;
	};
	marg(0,-1);
	return ans;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	rep(_,0,n) cout << solve() << endl;
}