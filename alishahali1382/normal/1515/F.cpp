#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=300010, LOG=20;

int n, m, u, v, x, y, t, a, b;
int dsu[MAXN];
ll A[MAXN], sum, X;
int par[MAXN], parid[MAXN], ans[MAXN];
vector<pii> G[MAXN];
set<pll> pq;

int getpar(int x){ return (dsu[x]==x?x:dsu[x]=getpar(dsu[x]));}
void dfs(int node){
	if (node!=1){
		for (pii &p:G[node]) if (p.first==par[node]) swap(G[node].back(), p);
		G[node].pop_back();
	}
	for (pii p:G[node]){
		par[p.first]=node;
		parid[p.first]=p.second;
		dfs(p.first);
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>X;
	for (int i=1; i<=n; i++){
		cin>>A[i];
		sum+=A[i];
		dsu[i]=i;
	}
	if (sum<(n-1ll)*X) kill("NO")
	for (int i=1; i<=m; i++){
		cin>>u>>v;
		if (getpar(u)==getpar(v)) continue ;
		dsu[getpar(u)]=dsu[getpar(v)];
		G[u].pb({v, i});
		G[v].pb({u, i});
//		debug2(u, v)
	}
	dfs(1);
	for (int i=2; i<=n; i++) pq.insert({A[i], i});
	iota(dsu+1, dsu+n+1, 1);
	for (int i=1; i<n; i++){
		int v=(pq.rbegin()->second);
		v=getpar(v);
//		debug(v)
		if (A[v]<X){
			while (getpar(G[1].back().first)==1) G[1].pop_back();
			v=G[1].back().first;
		}
		
		if (A[v]>=X || 1){
			ans[i]=parid[v];
			int u=getpar(par[v]);
			pq.erase({A[v], v});
			if (u!=1) pq.erase({A[u], u});
			A[u]+=A[v]-X;
			if (u!=1) pq.insert({A[u], u});
			dsu[v]=u;
			if (G[v].size()>G[u].size()) G[u].swap(G[v]);
			for (pii p:G[v]) G[u].pb(p);
			G[v].clear();
//			G[v].shrink_to_fit();
			continue ;
		}
	}
	
	cout<<"YES\n";
	for (int i=1; i<n; i++) cout<<ans[i]<<"\n";
	
	return 0;
}