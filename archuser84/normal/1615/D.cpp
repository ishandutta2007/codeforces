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
vector<int> A[N];
tuple<int,int,int> E[N];
int n, m;

int par[N]; int parp[N];

pii root(int v){
	if(par[v] == -1) return {v, 0};
	auto ans = root(par[v]);
	ans.second ^= parp[v];
	par[v] = ans.first;
	parp[v] = ans.second;
	return ans;
}

bool unite(int v, int u, int p){
	auto [a, e1] = root(v);
	auto [b, e2] = root(u);
	p ^= e1^e2;
	if(a==b && p) return 0;
	if(a==b) return 1;
	par[b] = a;
	parp[b] = p;
	return 1;
}

int getpar(int v){
	return root(v).second;
}

void solve()
{
	cin >> n >> m;
	Loop(i,0,n+1) par[i]=-1;
	bool flg = 1;
	Loop(i,0,n-1){
		int v, u, w;
		cin >> v >> u >> w; --v; --u;
		E[i] = {v, u, w};
		if(w!=-1) flg&=unite(v,u,__builtin_popcount(w)&1);
	}
	Loop(i,0,m){
		int v, u, w;
		cin >> v >> u >> w; --v; --u;
		flg &= unite(v,u,w);
	}
	if(!flg) {cout << "NO\n"; return;}
	cout << "YES\n";
	Loop(i,0,n-1){
		auto [v, u, w] = E[i];
		if(w!=-1) cout << v+1 << ' ' << u+1 << ' ' << w << '\n';
		else cout << v+1 << ' ' << u+1 << ' ' << (getpar(v)^getpar(u)) << '\n';
	}
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) solve();
}