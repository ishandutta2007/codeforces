#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

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

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 200010, LOG=19;

struct DSU{
	int par[MAXN];
	DSU(){
		iota(par, par+MAXN, 0);
	}
	int get(int x){
		if (par[x]==x) return x;
		return par[x]=get(par[x]);
	}
	void join(int x, int y){
		par[get(x)]=get(y);
	}
} dsu;

int n, m, k, u, v, x, y, t, a, b, ans;
int par[MAXN][LOG], h[MAXN];
int goodid[MAXN];
int D[MAXN], P[MAXN];
vector<int> G[MAXN];
queue<int> Q;

void dfs1(int node){
	h[node]=h[par[node][0]]+1;
	for (int i=1; i<LOG; i++) par[node][i]=par[par[node][i-1]][i-1];
	for (int v:G[node]) if (v!=par[node][0]){
		par[v][0]=node;
		dfs1(v);
	}
}

inline int GetPar(int v, int k){
	for (int i=0; i<LOG; i++) if (k&(1<<i)) v=par[v][i];
	return v;
}

int Lca(int x, int y){
	if (h[x]>h[y]) swap(x, y);
	y=GetPar(y, h[y]-h[x]);
	if (x==y) return x;
	for (int i=LOG-1; ~i; i--) if (par[x][i]!=par[y][i]) x=par[x][i], y=par[y][i];
	return par[x][0];
}

inline int GetKth(int u, int v, int k){ // 0-based (k=0 ==> u)
	int lca=Lca(u, v);
	if (h[u]-h[lca]==k) return lca;
	if (h[u]-h[lca]>k) return GetPar(u, k);
	k-=h[u]-h[lca];
	return GetPar(v, h[v]-h[lca]-k);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k>>m;
	for (int i=1; i<n; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	memset(D, 63, sizeof(D));
	while (m--){
		cin>>x;
		D[x]=0;
		P[x]=x;
		Q.push(x);
	}
	
	while (Q.size()){
		int v=Q.front();
		Q.pop();
		for (int u:G[v]) if (D[v]+1<D[u]){
			D[u]=D[v]+1;
			P[u]=P[v];
			Q.push(u);
		}
	}
	for (int v=1; v<=n; v++) for (int u:G[v]) if (u<v && D[u]+D[v]+1<=k) dsu.join(P[u], P[v]);
	for (int i=1; i<=n; i++) if (D[i]<=(k/2)) goodid[i]=dsu.get(P[i]);
	
	dfs1(1);
	
	cin>>m;
	while (m--){
		cin>>x>>y;
		int lca=Lca(x, y), dist=h[x]+h[y]-2*h[lca];
		if (dist<=k){
			cout<<"YES\n";
			continue ;
		}
		x=GetKth(x, y, (k+1)/2);
		y=GetKth(y, x, (k+1)/2);
		
		if (goodid[x]==goodid[y] && goodid[x]){
			cout<<"YES\n";
			continue ;
		}
		cout<<"NO\n";
	}
	
	return 0;
}