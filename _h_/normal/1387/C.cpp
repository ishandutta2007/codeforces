#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef unsigned long long ull;
typedef pair<int,ull> pil;
typedef vector<ull> vl;

const ull inf = 1LL<<63;

pil app(pil a, int x){
	return pil( a.first+1, (a.second<<1) ^ x );
}

pil succ(pil a){
	return pil( a.first-1, a.second & ~(1LL << (a.first-1)) );
}

pil pred(pil a){
	return pil( a.first-1, a.second >> 1 );
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int g, n, m;
	cin >> g >> n >> m;

	vector<vi> sing(g);
	vector<vector<pii>> lft(g), rgt(g);
	auto mk_new = [&](){
		int ans = sz(sing);
		sing.resize(ans+1);
		lft.resize(ans+1);
		rgt.resize(ans+1);
		return ans;
	};
	rep(_,0,n){
		int a, k, b, c;
		cin >> a >> k;
		if(k == 1){
			cin >> b;
			sing[b].push_back(a);
		} else {
			rep(_, 0, k-2){
				cin >> b;
				int nx = mk_new();
				lft[b].emplace_back(nx, a);
				rgt[nx].emplace_back(b, a);
				a = nx;
			}
			cin >> b >> c;
			lft[b].emplace_back(c, a);
			rgt[c].emplace_back(b, a);
		}
	}

	set<pil> anti;
	rep(_,0,m){
		int l;
		pil cur(0, 0);
		cin >> l;
		rep(_,0,l){
			int x;
			cin >> x;
			cur = app(cur, x);	
		}
		anti.insert(cur);
	}
	map<pil, int> ren;
	ren[pil(0, 0)] = 0;
	function<bool(pil)> ins = [&](pil p){
		if(ren.count(p)) return true;
		if(!ins(pred(p))) return false;
		for(pil q = p; q.first; q = succ(q))
			if(anti.count(q))
				return false;
		ren[p] = 0;
		return true;
	};
	trav(p, anti) ins(pred(p));

	int ix = 0;
	trav(pa, ren) pa.second = ix++;

	vector<vi> pre_app(ix, vi(2));

	rep(d,0,2) trav(pa, ren){
		pil p = pa.first;
		if(ren.count(app(p, d))){
			pre_app[pa.second][d] = ren[app(p, d)];	
		} else if(anti.count(app(p, d))) {
			pre_app[pa.second][d] = -1;
		} else if(p.first){
			pil q = succ(p);
			while(!ren.count(q)) q = succ(q);
			pre_app[pa.second][d] = pre_app[ren[q]][d];
		} else {
			pre_app[pa.second][d] = 0;
		}
		//cerr << pa.second << " " << d << " " << pre_app[pa.second][d] << endl;	
	}

	vector<vector<vl>> dp(sz(sing), vector<vl>(ix, vl(ix, inf)));
	vector<vector<vl>> pd(sz(sing), vector<vl>(ix, vl(ix, inf)));

	priority_queue<pair<ull, pair<int, pii>>> pq;

	auto todo = [&](ull len, int res, int fr, int to){
		if(len < pd[res][fr][to]){
			pd[res][fr][to] = len;
			pq.push({inf - len, {res, {fr, to}}});
		}
	};

	rep(d,0,2) rep(i,0,ix) if(pre_app[i][d] != -1)
		todo(1, d, i, pre_app[i][d]);

	vl rek(sz(sing), inf);
	
	auto doto = [&](ull len, int res, int fr, int to){
		if(pd[res][fr][to] < len) return;
		dp[res][fr][to] = len;
		rek[res] = min(rek[res], len);
		trav(ser, sing[res]) todo(len, ser, fr, to);
		trav(pa, lft[res]){
			int ri = pa.first, ser = pa.second;
			rep(i,0,ix) if(dp[ri][to][i] < inf)
				todo(len + dp[ri][to][i], ser, fr, i);
		}
		trav(pa, rgt[res]){
			int le = pa.first, ser = pa.second;
			rep(i,0,ix) if(dp[le][i][fr] < inf)
				todo(len + dp[le][i][fr], ser, i, to);
		}
	};

	while(!pq.empty()){
		auto t = pq.top(); pq.pop();
		doto(inf - t.first, t.second.first, t.second.second.first, t.second.second.second);
	}

	rep(i,2,g){
		if(rek[i] == inf) cout << "YES" << endl;
		else cout << "NO" << " " << rek[i] << endl;
	}
}