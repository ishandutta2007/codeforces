// written by aitch
// on 2019 12/17 at 16:05:00
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

// possible structures of an almost k uniform set:
// - just one node
//
// - k = 2l, and there is some edge such that all elements have
//   distance l to one of the endpoints, all in different ways
//
// - k = 2l-1, and there is some node, such that all elements have
//   distance l to it, all in different ways
//   except maybe one element has distance l-1
//
// - k = 2l, and there is some node, such that all elements have
//   distance l to it, all in different ways

void maxeq(int &x, int y){
	x = max(x,y);
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<vi> gr(n);

	rep(_,1,n){
		int u,v;
		cin >> u >> v;
		--u, --v;
		gr[u].emplace_back(v);
		gr[v].emplace_back(u);
		}

	vi uh(n,0), dh(n,1), par(n);
	par[0] = -1;

	function<void(int)> dfs0 = [&](int v){
		trav(u, gr[v]) if(u != par[v]){
			par[u] = v;
			dfs0(u);
			dh[v] = max(dh[v], 1+dh[u]);
		}
	};
	dfs0(0);
	function<void(int)> dfs1 = [&](int v){
		int mx = 0;
		trav(u, gr[v]) if(u == par[v]){
			mx = max(mx, uh[v]);
		} else {
			mx = max(mx, dh[u]);	
		}
		int w = -1, m2 = 0;
		trav(u, gr[v]) if(u == par[v]){
			if(mx == uh[v]) w = -2;
			else m2 = max(m2, uh[v]);
		} else {
			if(mx == dh[u]){
				if(w == -1) w = u;
				else w = -2;
			} else {
				m2 = max(m2, dh[u]);
			}
		}
		trav(u, gr[v]) if(u != par[v]){
			if(u == w){
				uh[u] = 1 + m2;
			} else {
				uh[u] = 1 + mx;
			}
			dfs1(u);
		}
	};
	dfs1(0);

	vi ans(n+1,1);

	vector<pii> pas;

	rep(c,0,n){
		vi ls = {0};
		trav(u,gr[c]) if(u!=par[c]){
			ls.push_back(dh[u]);
		} else {
			ls.push_back(uh[c]);
		}
		trav(h, ls) pas.emplace_back(h, c);
		sort(all(ls));
		reverse(all(ls));
		rep(j,1,sz(ls)){
			maxeq(ans[2*ls[j]], j+1);
			if(ls[j]) maxeq(ans[2*ls[j]-1], j+1);
			if(ls[j-1] > ls[j])
				maxeq(ans[2*ls[j]+1], j+1);
		}
	}
	sort(all(pas));
	reverse(all(pas));

	vi cnt(n), bestchild(n);

	auto upd = [&](int v, int &x){
		if(v < 0) return;
		maxeq(x, cnt[v] + bestchild[v] - 2);
	};

	trav(pa, pas){
		++cnt[pa.second];
		if(pa.second) maxeq(bestchild[par[pa.second]],
			cnt[pa.second]);
		if(pa.first*2 <= n){
			upd(pa.second, ans[pa.first*2]);
			upd(par[pa.second], ans[pa.first*2]);
		}
	}


	rrep(i,3,n+1) ans[i-2] = max(ans[i-2], ans[i]);

	rep(i,1,n+1) cout << ans[i] << " ";
	cout << endl;
}