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
	vi d(n);
	trav(x, d) cin >> x;
	if(count(all(d), -1) == 0 && count(all(d),1)%2 != 0){
		cout << -1 << endl;
		return 0;
	}
	vector<vector<pii>> es(n);
	vi us(m), vs(m);
	rep(i,0,m){
		int u,v;
		cin >> u >> v;
		--u, --v;
		us[i] = u, vs[i] = v;
		es[u].emplace_back(i+1, v);
		es[v].emplace_back(i+1, u);
	}
	vi par(n,-1), pix(n, -1);
	par[0] = -2;
	function<void(int)> dfs = [&](int v){
		trav(e, es[v]) if(par[e.second] == -1){
			par[e.second] = v;
			pix[e.second] = e.first;
			dfs(e.second);
		}
	};
	dfs(0);
	vector<bool> ba(n);
	if(count(all(d),1)%2 == 1){
		rep(i,0,n){
			if(d[i]==-1){
				d[i] = 1;
				break;
			}
		}
	}
	rep(i,0,n) if(d[i]==1) ba[i] = 1; 
	vi ans;
	function<void(int)> dfs2 = [&](int v){
		trav(e, es[v]) if(pix[e.second]==e.first){
			dfs2(e.second);
			ba[v] = ba[v] ^ ba[e.second];
		}
		if(ba[v]){
			assert(v);
			assert(pix[v] >= 1);
			ans.push_back(pix[v]);
		}
	};
	dfs2(0);

	vi deg(n);
	trav(i, ans) ++deg[us[i-1]], ++deg[vs[i-1]];
	rep(i,0,n) assert(deg[i]%2 == d[i] || d[i]==-1);

	cout << sz(ans) << endl;
	sort(all(ans));
	trav(i, ans) cout << i << endl;
}