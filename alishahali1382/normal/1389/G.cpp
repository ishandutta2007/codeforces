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
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=300010, LOG=20;

int n, m, k, u, v, x, y, t, a, b;
int U[MAXN], V[MAXN], W[MAXN], cut[MAXN];
int h[MAXN], par[MAXN], comp[MAXN], sz[MAXN];
bool good[MAXN], mark[MAXN];
ll C[MAXN], dp[MAXN], ans[MAXN];
vector<pii> G[MAXN];

int dfs1(int node, int parid){
	int res=h[node]=h[par[node]]+1;
	mark[node]=1;
	for (pii p:G[node]){
		int v=p.first, id=p.second;
		if (v==par[node]) continue ;
		if (mark[v]) res=min(res, h[v]);
		else{
			par[v]=node;
			res=min(res, dfs1(v, id));
			sz[node]+=sz[v];
		}
	}
//	debug2(node, sz[node])
	if ((res==h[node] && sz[node] && sz[node]<k) || node==1) cut[parid]=1, comp[node]=node;
	else comp[node]=par[node];
	return res;
}
int getcomp(int v){ return (comp[v]==v?v:comp[v]=getcomp(comp[v]));}
ll dfs2(int node){
	for (pii p:G[node]) if (p.first!=par[node]){
		int v=p.first, w=p.second;
		par[v]=node;
		dp[node]+=max(0ll, dfs2(v)-w);
	}
	return dp[node]+=C[node];
}
void dfs3(int node){
	ans[node]=dp[node];
	for (pii p:G[node]) if (p.first!=par[node]){
		int v=p.first, w=p.second;
		dp[node]-=max(0ll, dp[v]-w);
		dp[v]+=max(0ll, dp[node]-w);
		dfs3(v);
		dp[v]-=max(0ll, dp[node]-w);
		dp[node]+=max(0ll, dp[v]-w);
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>k;
	for (int i=0; i<k; i++) cin>>x, good[x]=sz[x]=1;
	for (int i=1; i<=n; i++) cin>>C[i];
	for (int i=1; i<=m; i++) cin>>W[i];
	for (int i=1; i<=m; i++){
		cin>>U[i]>>V[i];
		G[U[i]].pb({V[i], i});
		G[V[i]].pb({U[i], i});
	}
	dfs1(1, 0);
	for (int i=1; i<=n; i++) G[i].clear();
	for (int i=1; i<=m; i++) if (cut[i]){
		int u=getcomp(U[i]), v=getcomp(V[i]);
		G[u].pb({v, W[i]});
		G[v].pb({u, W[i]});
	}
	for (int i=1; i<=n; i++) if (getcomp(i)^i) C[getcomp(i)]+=C[i];
	dfs2(1);
	dfs3(1);
	for (int v=1; v<=n; v++) cout<<ans[getcomp(v)]<<" \n"[v==n];
	
	return 0;
}