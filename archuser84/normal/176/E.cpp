///
///    Hashire sori yo 
///    Kaze no you ni  
///    Tsukimihara wo  
///    PADORU PADORU   
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

#define int ll
#define pii pll

const int N = 100'010;

namespace rmq
{
	vector<pii> a;
	pii b[20][2*N];
	int n;

	void build(){
		n = a.size();
		Loop(i,0,n) b[0][i] = a[i];
		for(int k = 0; k < 19; ++ k)
			for(int i = 0; i + (2<<k) <= n; ++i)
				b[k+1][i] = min(b[k][i], b[k][i+(1<<k)]);
	}

	pii get(int l, int r){
		int k = __lg(r-l);
		auto ans = min(b[k][l], b[k][r-(1<<k)]);
		return ans;
	}
}

vector<pii> A[N];
int tim[N], dep[N];
int n;

void dfs(int v, int p, int d){
	dep[v] = d; tim[v] = rmq::a.size();
	rmq::a.emplace_back(d,v);
	for(auto [u,w] : A[v]){
		if(u == p) continue;
		dfs(u,v,d+w);
		rmq::a.emplace_back(d,v);
	}
}

set<int> s; ll ans=0;

void add(int v){
	if(!s.size()){
		ans += dep[v];
	} else {
		auto it = s.upper_bound(tim[v]);
		int r = it==s.end()? rmq::a.size()-1: *it;
		int l = it==s.begin()? 0: *--it;
		l = rmq::get(l, tim[v]+1).second;
		r = rmq::get(tim[v], r+1).second;
		int u = dep[l]>dep[r]? l: r;
		ans += dep[v] - dep[u];
	}
	s.insert(tim[v]);
}

void rem(int v){ // Who's Rem?
	s.erase(tim[v]);
	if(!s.size()){
		ans -= dep[v];
	} else {
		auto it = s.upper_bound(tim[v]);
		int r = it==s.end()? rmq::a.size()-1: *it;
		int l = it==s.begin()? 0: *--it;
		l = rmq::get(l, tim[v]+1).second;
		r = rmq::get(tim[v], r+1).second;
		int u = dep[l]>dep[r]? l: r;
		ans -= dep[v] - dep[u];
	}
}

ll get(){
	if(s.empty()) return 0;
	int lca = rmq::get(*s.begin(), (*--s.end())+1).second;
	return ans-dep[lca];
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n;
	Loop(i,1,n){
		int v, u, w;
		cin >> v >> u >> w;
		--v; --u;
		A[v].push_back({u,w});
		A[u].push_back({v,w});
	}
	dfs(0,-1,0);
	rmq::build();
	int q;
	cin >> q;
	while(q--){
		char c; int x;
		cin >> c;
		if(c != '?') {cin >> x; --x;}
		if(c=='-') rem(x);
		if(c=='+') add(x);
		if(c=='?') cout << get() << '\n';
	}
}