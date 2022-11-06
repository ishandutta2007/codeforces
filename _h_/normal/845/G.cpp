#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = b; i --> (a);)
#define all(v) v.begin(),v.end()
#define trav(x,v) for(auto &x : v)
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	vi xs(m), ys(m), ws(m);
	rep(i,0,m) cin >> xs[i] >> ys[i] >> ws[i], --xs[i], --ys[i];
	vector<vector<pii>> gr(n);
	rep(i,0,m){
		gr[xs[i]].emplace_back(ys[i], ws[i]);
		gr[ys[i]].emplace_back(xs[i], ws[i]);
	}
	vi par(n, -1), h(n);
	par[0] = 0;
	function<void(int)> dfs = [&](int v){
		trav(pa, gr[v]) if(par[pa.first]==-1){
			par[pa.first] = v;
			h[pa.first] = h[v]^pa.second;
			dfs(pa.first);
		}
	};
	dfs(0);
	int len = h[n-1];
	vi alts(m);
	rep(i,0,m) alts[i] = h[xs[i]]^h[ys[i]]^ws[i];
	int lo = 0;
	rrep(i,0,30){
		rep(j,lo,m) if(alts[j]&(1<<i)){
			swap(alts[lo++], alts[j]);
			rep(k,lo,m)
				if(alts[k]&(1<<i))
					alts[k] ^= alts[lo-1];
			break;
		}
	}
	int hi = lo; lo = 0;
	rrep(i,0,30){
		if(lo < hi && (alts[lo] & (1<<i))){
			if(len & (1<<i)) len ^= alts[lo];
			lo++;
		}
	}
	cout << len << endl;
}