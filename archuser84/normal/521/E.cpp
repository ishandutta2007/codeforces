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

const int N = 200'010;
vector<pii> A[N];
int par[N];
bool vis[N];
int mark[N];
int up[N], down[N];
int n, m;

void make(int v, int e1, int e2)
{
	vector<int> vc[3];
	int u = v;

	vc[0].push_back(u);
	for(;;){
		u = par[u];
		vc[0].push_back(u);
		if(u == up[e2]) swap(e1,e2);
		if(u == up[e1]) break;
	}

	vc[1].push_back(u);
	for(int y = down[e1];;){
		vc[1].push_back(y);
		if(y == v) break;
		y = par[y];
	}

	vc[2].push_back(u);
	for(int y = u;;){
		if(y == up[e2]) break;
		y = par[y];
		vc[2].push_back(y);
	}
	for(int y = down[e2];;){
		vc[2].push_back(y);
		if(y == v) break;
		y = par[y];
	}

	reverse(vc[0].begin(), vc[0].end());

	cout << "YES\n";
	Loop(i,0,3){
		cout << vc[i].size() << ' ';
		for(int x : vc[i]) cout << x+1 << ' ';
		cout << '\n';
	}

	exit(0);
}

void dfs(int v)
{
	vis[v] = 1;
	for(auto [u, e] : A[v]){
		if(!vis[u]){
			par[u] = v;
			dfs(u);
		} else {
			if(u==par[v]) continue;
			if(up[e] != -1) continue;
			up[e] = u; down[e] = v;
			int x = v;
			while(x != u){
				if(mark[x] != -1) make(x,e,mark[x]);
				mark[x] = e;
				x = par[x];
			}
		}
	}
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	memset(par, -1, 4*N);
	memset(mark, -1, 4*N);
	memset(up, -1, 4*N);
	cin >> n >> m;
	Loop(i,0,m){
		int v, u;
		cin >> v >> u;
		--v; --u;
		A[v].push_back({u,i});
		A[u].push_back({v,i});
	}
	Loop(i,0,n) if(!vis[i]) dfs(i);
	cout << "NO\n";
}