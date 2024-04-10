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
using namespace std;

const int N = 100'010;
int cnt[N];
vector<pii> A[N];
int n;

int V[N], U[N], h[N], w[N];

void dfs1(int v, int p, int h)
{
	for(auto [u, e] : A[v]){
		if(u == p) continue;
		V[e] = v; U[e] = u; ::h[e] = h+1;
		dfs1(u, v, h+1);
	}
}

ll fans = 0;
vector<int> ans;

void up(int e, ll x){
	if(x > fans){fans=x;ans.clear();}
	if(x== fans)ans.push_back(e);
}

int par[N], sz[N];
int rt(int v){return par[v]==-1?v:(par[v]=rt(par[v]));}
void unite(int e){
	int v = V[e], u = U[e];
	assert(par[u]==-1);
	v = rt(v);
	par[u] = v;
	sz[v] += sz[u];
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n;
	Loop(i,1,n){
		int v, u;
		cin >> v >> u >> w[i]; --v; --u;
		A[v].emplace_back(u,i);
		A[u].emplace_back(v,i);
	}
	dfs1(0,-1,0);
	vector<tuple<int,int,int>> padoru;
	Loop(i,1,n) padoru.emplace_back(w[i], -h[i], i);
	sort(padoru.begin(), padoru.end());
	memset(par,-1,sizeof(par));
	fill(sz,sz+N,1);
	Loop(i,0,n-1){
		int w = get<0>(padoru[i]);
		vector<int> nero;
		while(get<0>(padoru[i]) == w)
			nero.push_back(get<2>(padoru[i++]));
		for(int e : nero) unite(e);
		for(int e : nero) up(e, 1ll*sz[U[e]]*(sz[rt(V[e])]-sz[U[e]]));
		--i;
	}
	cout << 2*fans << ' ' << ans.size() << '\n';
	sort(ans.begin(), ans.end());
	for(int e : ans) cout << e << ' ';
	cout << '\n';
}