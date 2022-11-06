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

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	vector<vi> gr(n);
	rep(_,1,n){
		int a, b;
		cin >> a >> b;
		--a, --b;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}

	vector<bool> col(n);

	function<void(int,int)> dfs = [&](int v, int par){
		trav(u, gr[v]) if(u != par){
			col[u] = !col[v];
			dfs(u, v);
		}
	};
	dfs(0, -1);

	int num = 0;
	set<int> nbrs;

	set<bool> seen;

	rep(v,0,n) if(sz(gr[v]) == 1){
		num++;
		nbrs.insert(gr[v][0]);
		seen.insert(col[v]);
	}

	int mn = sz(seen) == 1 ? 1 : 3;
	int max = n-1 + (sz(nbrs) - num);

	cout << mn << " " << max << endl;
}