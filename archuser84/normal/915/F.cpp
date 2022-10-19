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

const int N = 1e6+10;
vector<int> A[N];
int par[N];
int sz[N];
pii V[N];
pii w[N];

int rt(int v){return par[v]==-1?v:(par[v]=rt(par[v]));}
void unite(int a, int b){
	a = rt(a); b = rt(b);
	if(a==b) return;
	par[b] = a;
	sz[a] += sz[b];
}

int n;

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n;
	Loop(i,0,n) cin >> V[i].first, V[i].second=i;
	Loop(i,0,n) w[i] = V[i];
	Loop(i,1,n){
		int v, u;
		cin >> v >> u;
		--v; --u;
		A[v].push_back(u);
		A[u].push_back(v);
	}
	ll ans = 0;

	sort(V, V+n);
	fill(par, par+n, -1);
	fill(sz, sz+n, 1);
	Loop(i,0,n){
		int v = V[i].second;
		ll sum = 1, sum2 = 0;
		for(int u : A[v]){
			if(w[u] < w[v]){
				ll sz = ::sz[rt(u)];
				sum += sz; sum2 += sz*(sz-1)/2;
				unite(v, u);
			}
		}
		sum = sum*(sum-1)/2;
		sum -= sum2;
		ans += sum*w[v].first;
	}

	reverse(V, V+n);
	fill(par, par+n, -1);
	fill(sz, sz+n, 1);
	Loop(i,0,n){
		int v = V[i].second;
		ll sum = 1, sum2 = 0;
		for(int u : A[v]){
			if(w[u] > w[v]){
				ll sz = ::sz[rt(u)];
				sum += sz; sum2 += sz*(sz-1)/2;
				unite(v, u);
			}
		}
		sum = sum*(sum-1)/2;
		sum -= sum2;
		ans -= sum*w[v].first;
	}

	cout << ans << '\n';
}