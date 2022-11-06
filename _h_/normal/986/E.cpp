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

const ll md = 1e9+7;
const int lim = 1e7+1; 

ll mexp(ll a, ll e){
	ll res = 1;
	while(e){
		if(e&1) res = res * a % md;
		a = a * a % md;
		e /= 2;
	}
	return res;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	vi gpf(lim);
	rep(p,2,lim) if(!gpf[p])
		for(int i = p; i < lim; i += p)
			gpf[i] = p;

	int n;
	cin >> n;
	
	vector<vi> gr(n);
	rep(_,1,n){
		int u,v;
		cin >> u >> v;
		--u, --v;
		gr[u].push_back(v);
		gr[v].push_back(u);
	}
	vi a(n);
	trav(x, a) cin >> x;

	int lg = 0;
	while( (1<<lg) < n) ++lg;
	vector<vi> hopp(lg, vi(n, -1));
	vi h(n);
	vi lnum(n), rnum(n);
	int ix = 0;

	function<void(int)> dfs = [&](int v){
		lnum[v] = ix++;
		trav(u, gr[v]) if(u != hopp[0][v]){
			hopp[0][u] = v;
			h[u] = h[v]+1;
			dfs(u);
		}
		rnum[v] = ix++;
	};
	dfs(0);

	hopp[0][0] = 0;
	rep(i,1,lg) rep(j,0,n)
		hopp[i][j] = hopp[i-1][hopp[i-1][j]];

	auto jump = [&](int v, int l){
		for(int i = 0; l; ++i){
			if(l & (1<<i)){
				v = hopp[i][v];
				l -= 1<<i;
			}
		}
		return v;
	};

	auto lca = [&](int u, int v){
		if(h[u] > h[v]) swap(u, v);
		v = jump(v, h[v]-h[u]);
		if(u == v) return u;

		rrep(i,0,lg){
			int vv = hopp[i][v], uu = hopp[i][u];
			if(vv != uu){
				v = vv;
				u = uu;
			}
		}
		return hopp[0][u];
	};

	auto factor = [&](int m, vi &res){
		while(m > 1){
			int p = gpf[m], q = 1;
			while(m % p == 0){
				m /= p;
				q *= p;
				res.push_back(q);
			}
		}
	};

	vector<vector<pii>> pre(lim);
	rep(i,0,n){
		vi ls;
		factor(a[i], ls);
		trav(q, ls){
			pre[q].emplace_back(lnum[i],1);
			pre[q].emplace_back(rnum[i],-1);
		}
	}
	trav(m, pre){
		if(m.empty()) continue;
		sort(all(m));
		rep(i,1,sz(m))
			m[i].second += m[i-1].second;
	}

	auto cnt = [&](int q, int pos){
		int lo = -1, hi = sz(pre[q]);
		while(lo+1 < hi){
			int mi = (lo+hi)/2;
			if(pre[q][mi].first > pos) hi = mi;
			else                       lo = mi;
		}
		if(lo == -1) return 0;
		return pre[q][lo].second;
	};

	int q;
	cin >> q;
	rep(_,0,q){
		int u, v, x;
		cin >> u >> v >> x;
		--u, --v;
		int w = lca(u,v);
		vi ls;
		factor(x, ls);
		
		ll ans = 1;
		trav(q, ls){
			if(pre[q].empty()) continue;
			int c = cnt(q, lnum[u])
			      + cnt(q, lnum[v])
			      - cnt(q, lnum[w])
			      - cnt(q, lnum[w]-1);

			ans *= mexp(gpf[q], c);
			ans %= md;
		}
		cout << ans << endl;
	}
}