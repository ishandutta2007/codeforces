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
vector<pii> A[N];
bool bad[N];
pii e[N], a[N];
int n, m;

int par[N];
int rt(int v){return par[v]==-1?v:par[v]=rt(par[v]);}
void unite(int v, int u){
	v = rt(v); u = rt(u);
	if(v == u) return;
	par[u] = v;
}

int lst[N];
vector<pii> B[N];
bool cut[N];
int h[N];
int dfs(int v, int p, int hh=1){
	h[v] = hh;
	int ans = h[v];
	for(auto [u, e] : B[v]){
		if(e == p) continue;
		if(h[u]) ans = min(ans, h[u]);
		else {
			auto x = dfs(u, e, hh+1);
			if(x > h[v]) cut[e] = 1;
			ans = min(ans, x);
		}
	}
	return ans;
}

vector<int> cv;
void up(int v, int t){
	if(lst[v] == t) return;
	lst[v] = t;
	B[v].clear();
	h[v] = 0;
	cv.push_back(v);
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> m;
	Loop(i,0,m)
	{
		int v, u, w;
		cin >> v >> u >> w;
		--v; --u;
		A[v].emplace_back(u,w);
		A[u].emplace_back(v,w);
		a[i] = {w, i};
		e[i] = {v, u};
	}
	memset(par,-1,sizeof par);
	sort(a, a+m);
	Loop(i,0,m){
		vector<int> E; int w = a[i].first;
		while(i < m && a[i].first == w)
			E.push_back(a[i++].second);
		cv.clear();
		for(int e : E){
			int v = ::e[e].first, u = ::e[e].second;
			v = rt(v); u = rt(u);
			up(v, i); up(u, i);
			if(v == u) bad[e] = 1;
			else {
				B[v].emplace_back(u,e);
				B[u].emplace_back(v,e);
			}
		}
		for(int v : cv) if(!h[v]) dfs(v, -1);
		for(int e : E) unite(::e[e].first, ::e[e].second);
		--i;
	}
	Loop(i,0,m) cout << (bad[i]?"none":cut[i]?"any":"at least one") << '\n';
}