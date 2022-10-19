///
///   What would happen if we used assembly language for CP?
///   Sorry, that was a strange thing to ask.
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

const int N = 1010;
ll cap[N][N];
vector<int> A[N];
ll sume;
int n, m;

int par[N];
vector<pll> q;
ll bfs(int s, int t){
	q.clear();
	par[s] = -2;
	q.emplace_back(s,1e18);
	for(int _=0; _<q.size(); ++_){
		auto [v, f] = q[_];
		for(int u : A[v]){
			if(par[u] != -1 || !cap[v][u]) continue;
			ll nf = min(f, cap[v][u]);
			par[u] = v;
			q.emplace_back(u,nf);
			if(u==t) return nf;
		}
	}
	return 0;
}

ll flow(int s, int t){
	memset(par,-1,sizeof par);
	ll ans=0, f;
	while(f = bfs(s,t)){
		for(int v=t; v!=s;){
			int u = par[v];
			cap[u][v] -= f;
			cap[v][u] += f;
			v = u;
		}
		for(auto [v, f] : q)
			par[v] = -1;
		ans += f;
	}
	return ans;
}

void adde(int v, int u, ll f){
	A[v].push_back(u);
	A[u].push_back(v);
	cap[v][u] += f;
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> m;
	Loop(i,0,n){
		ll x;
		cin >> x;
		adde(i,n+1,2*x);
	}
	Loop(i,0,m){
		int v, u; ll e;
		cin >> v >> u >> e;
		--v; --u;
		adde(v,u,e); cap[u][v] += e;
		adde(n,v,e);
		adde(n,u,e);
		sume += 2*e;
	}
	cout << (sume-flow(n,n+1))/2 << '\n';
}