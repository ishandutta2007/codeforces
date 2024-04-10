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

const int inf = 1e9+1;

void psh(pii pa, map<int,int> &s){
	int h = pa.first, w = pa.second;
	while(true){
		auto it = s.upper_bound(h);
		if(it == s.begin()) break;
		--it;
		if(it->second >= w) s.erase(it);
		else break;
	}
	auto it = s.lower_bound(h);
	if(it != s.end() && it->second <= w) return;
	s[h] = w;
}

struct UF {
	vi t;
	int comps;
	UF(int n){
		t.resize(n, -1);
		comps = n;
	}
	int find(int a){
		return t[a]<0 ? a : t[a] = find(t[a]);
	}
	bool uni(int a, int b){
		a = find(a), b = find(b);
		if(a == b) return false;
		if(t[a] < t[b]) swap(a,b);
		t[b] += t[a];
		t[a] = b;
		--comps;
		return true;
	}
};

struct Tree {
	int n;

	vector<vi> par;
	vi de;
	vector<vi> ch;
	int lg = 0;

	Tree(int n1, vector<vi> &gr){
		n = n1;

		de.resize(n);
		ch.resize(n);

		while((1<<lg) < n-1) ++lg;
		++lg;
		par.resize(lg, vi(n));
		par[0][0] = 0;

		stack<int> st;
		st.push(0);
		while(!st.empty()){
			int v = st.top(); st.pop();
			trav(u, gr[v]) if(u != par[0][v]){
				par[0][u] = v;
				ch[v].push_back(u);
				st.push(u);
				de[u] = de[v]+1;
			}
		}

		rep(t,1,lg) rep(i,0,n) par[t][i] = par[t-1][par[t-1][i]];

	}

	int jump(int a, int s){
		rrep(t,0,lg) if(s >= (1<<t)){
			s -= 1<<t;
			a = par[t][a];
		}
		return a;
	}

	int lca(int a, int b){
		if(de[a] > de[b]) swap(a,b);

		b = jump(b, de[b]-de[a]);
		if(a == b) return a;

		rrep(t,0,lg){
			int x = par[t][a], y = par[t][b];
			if(x != y){
				a = x, b = y;
			}
		}
		return par[0][a];
	}

	void fun(vector<pii> &es, vi &w, vi &res){
		res.resize(n, inf);

		vector<vector<pii>> ps(n);

		rep(i,0,sz(es)){
			pii pa = es[i];
			int u = pa.first, v = pa.second;
			if(u == v) continue;
			int r = lca(u, v);

			if(r != u) ps[u].emplace_back( -de[r], w[i] );
			if(r != v) ps[v].emplace_back( -de[r], w[i] );
		}
		function<void(int,map<int,int>&)> rek = [&](int v, map<int,int> &s){
			trav(u, ch[v]){
				map<int,int> t;
				rek(u, t);
				if(sz(t) > sz(s)) swap(s,t);
				trav(x, t) psh(x, s);
			}
			trav(x, ps[v]) psh(x, s);
			if(!s.empty() && s.begin()->first == -de[v])
				s.erase(s.begin());
			res[v] = s.empty() ? inf : s.begin()->second;
		};
		map<int,int> s;
		rek(0, s);
	}
};

int main(){
	
	int n, k, m;
	cin >> n >> k >> m;

	vi ga(k), gb(k);
	vi fa(m), fb(m), fw(m);
	rep(i,0,k) scanf("%d%d", &ga[i], &gb[i]);
	rep(i,0,m) scanf("%d%d%d", &fa[i], &fb[i], &fw[i]);
	trav(x, ga) --x;
	trav(x, gb) --x;
	trav(x, fa) --x;
	trav(x, fb) --x;

	UF uf(n);
	rep(i,0,k) uf.uni(ga[i], gb[i]);

	int t = uf.comps;
	map<int, int> ren;
	int ix = 0;
	rep(i,0,n) if(i == uf.find(i)) ren[i] = ix++;

	vi myr(n), myi(n);
	vector<vi> ls(t);
	vector<vector<vi>> grs(t);
	rep(i,0,n){
		myr[i] = ren[uf.find(i)];
		int j = myr[i];
		myi[i] = sz(ls[j]);
		ls[j].push_back(i);
	}
	rep(i,0,t) grs[i].resize(sz(ls[i]));
	rep(i,0,k){
		int j = myr[ga[i]];
		int s = myi[ga[i]], t = myi[gb[i]];
		grs[j][s].push_back(t);
		grs[j][t].push_back(s);
	}
	ren.clear();

	vi p(m);
	rep(i,0,m) p[i] = i;
	sort(all(p), [&](int x, int y){
			return fw[x] < fw[y];
		});

	UF fu(t);
	vector<vi> gr(t), grf(t);
	trav(i, p){
		int u = fa[i], v = fb[i];
		u = myr[u], v = myr[v];
		if(fu.uni(u, v)){
			gr[u].push_back(v);
			gr[v].push_back(u);
			grf[u].push_back(2*i);
			grf[v].push_back(2*i+1);
		}
	}
	Tree trs(t, gr);
	vi topar(t), parm(t);
	rep(i,0,t) rep(j,0,sz(gr[i])) if(gr[i][j] == trs.par[0][i]){
		int ix = grf[i][j];
		int bo = ix%2;
		ix /= 2;
		if(!bo){
			topar[i] = fa[ix];
			parm[i] = fb[ix];
		} else {
		       	topar[i] = fb[ix];	
			parm[i] = fa[ix];
		}
	}
	
	vector<vector<pii>> ess(t);
	vector<vi> ws(t);

	vector<pii> es;
	vi w;

	rep(i,0,m){
		int u = myr[fa[i]], v = myr[fb[i]];		
		if(u == v){
			ess[u].emplace_back(fa[i], fb[i]);	
			ws[u].push_back(fw[i]);
			continue;
		}
		int r = trs.lca(u, v);
		if(r == v){
			swap(u, v);
			swap(fa[i], fb[i]);
		}
		if(r == u){
			int m = trs.jump(v, trs.de[v]-trs.de[u]-1);
			ess[u].emplace_back(fa[i], parm[m]);
			ws[u].push_back(fw[i]);

			ess[v].emplace_back(fb[i], topar[v]);
			ws[v].push_back(fw[i]);

			es.emplace_back(v, m);
			w.emplace_back(fw[i]);
		} else {
			int m1 = trs.jump(v, trs.de[v]-trs.de[r]-1);
			int m2 = trs.jump(u, trs.de[u]-trs.de[r]-1);
			ess[r].emplace_back(parm[m1], parm[m2]);
			ws[r].push_back(fw[i]);

			ess[v].emplace_back(fb[i], topar[v]);
			ws[v].push_back(fw[i]);

			ess[u].emplace_back(fa[i], topar[u]);
			ws[u].push_back(fw[i]);

			es.emplace_back(v, m1);
			w.push_back(fw[i]);

			es.emplace_back(u, m2);
			w.push_back(fw[i]);
		}
	}

	vi res;
	trs.fun(es, w, res);

	rep(i,0,t) if(res[i] < inf){
		int j = trs.par[0][i];
		int s = topar[j], t = parm[i];
		ess[j].emplace_back(s,t);
		ws[j].push_back(res[i]);
	}

	ll ans = 0;

	rep(i,0,t){
		Tree tr(sz(ls[i]), grs[i]);

		trav(pa, ess[i]){
			pa.first = myi[pa.first];
			pa.second = myi[pa.second];
		}

		vi rs;
		tr.fun(ess[i], ws[i], rs);
		rep(j,1,sz(ls[i])){
			ll x = rs[j];
			if(x == inf){
				cout << -1 << endl;
				return 0;
			}
			ans += x;
		}
	}

	cout << ans << endl;
	exit(0);
}