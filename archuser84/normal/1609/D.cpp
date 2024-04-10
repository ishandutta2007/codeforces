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

const int N = 1010;
int sz[N], par[N];
multiset<int,greater<int>> ms;

int rt(int v){return par[v]==-1?v:(par[v]=rt(par[v]));}
int unite(int v, int u)
{
	v = rt(v);
	u = rt(u);
	if(v == u) return sz[v];
	par[u]=v;
	ms.erase(ms.lower_bound(sz[v]));
	ms.erase(ms.lower_bound(sz[u]));
	sz[v]+=sz[u];
	ms.insert(sz[v]);
	return sz[v];
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);
	memset(par, -1, sizeof par);
	fill(sz,sz+N,1);
	int n, d;
	cin >> n >> d;
	while(n--) ms.insert(1);
	int kooft=1;
	while(d--){
		int v, u;
		cin >> v >> u;
		if(rt(v) == rt(u)) ++kooft;
		else unite(v, u);
		int ans = 0;
		auto it = ms.begin(); int rem = kooft;
		for(; rem; ++it, --rem) ans += (*it);
		cout << ans-1 << '\n';
	}
}