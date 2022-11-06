#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (b);)
#define trav(x,v) for(auto &x : (v))
#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	vector<vi> gr(n);
	rep(_,1,n){
		int u, v;
		cin >> u >> v;
		--u, --v;
		gr[u].push_back(v);
		gr[v].push_back(u);
	}

	int T = 0;
	trav(v, gr) T = max(T, sz(v));

	vector<pii> ans;

	function<void(int,int,int)> dfs = [&](int v, int par, int t0){
		ans.emplace_back(v, t0);	
		int cur = t0, lft = 0;
		trav(u, gr[v]) if(u != par) lft++;
		trav(u, gr[v]) if(u != par){
			if(cur == T){
				cur = t0-1-lft;
				ans.emplace_back(v, cur);
			}
			dfs(u, v, cur+1);
			cur += 1;
			ans.emplace_back(v, cur);
			--lft;
		}
		if(v && cur+1 > t0){
			ans.emplace_back(v, t0-1);
		}
	};
	dfs(0,-1,0);

	cout << sz(ans) << endl;
	trav(pa, ans) cout << 1+pa.first << " " << pa.second << endl;
}