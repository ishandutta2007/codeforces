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

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int MAXN=100010, LOG=20;

ll n, m, K, u, v, X, Y, t, a, b, ans, shit;
ll A[MAXN], f[MAXN], g[MAXN];
ll tav[MAXN];
int h[MAXN];
ll up[MAXN], dwn[MAXN];
int sz[MAXN];
bool dead[MAXN];
vector<int> G[MAXN];
vector<int> v1, v2;
int mp1[MAXN], mp2[MAXN];

int dfs1(int node, int par){
	sz[node]=1;
	for (int v:G[node]) if (!dead[v] && v!=par) sz[node]+=dfs1(v, node);
	return sz[node];
}
int Centroid(int node, int par, int n){
	for (int v:G[node]) if (!dead[v] && v!=par && 2*sz[v]>=n) return Centroid(v, node, n);
	return node;
}

void dfs2(int node, int par){
//	debug(node)
	v2.pb(node);
	h[node]=h[par]+1;
	dwn[node]=(dwn[par]+A[node]*tav[h[node]])%Y;
	up[node]=(K*up[par]+A[node])%Y;
	for (int v:G[node]) if (v!=par && !dead[v]) dfs2(v, node);
}

ll powmod(ll a, ll b){
	b%=Y-1;
	if (b<0) b+=Y-1;
	ll res=1;
	for (; b; b>>=1, a=a*a%Y) if (b&1) res=res*a%Y;
	return res;
}

void Calc(vector<int> &vec, int w){
	int s1=0, s2=0;
	for (int u:vec) mp1[s1++]=dwn[u];
	sort(mp1, mp1+s1);
	for (int v:vec){
		ll tmp=X-up[v];
		tmp=tmp*powmod(K, Y-1-h[v])%Y;
		if (tmp<0) tmp+=Y;
		int gt=upper_bound(mp1, mp1+s1, tmp)-lower_bound(mp1, mp1+s1, tmp);
		g[v]+=gt*w;
		mp2[s2++]=tmp;
	}
	sort(mp2, mp2+s2);
	for (int u:vec){
		int gt=upper_bound(mp2, mp2+s2, dwn[u])-lower_bound(mp2, mp2+s2, dwn[u]);
		f[u]+=gt*w;
	}
}

void Decompose(int root){
	root=Centroid(root, root, dfs1(root, root));
	dead[root]=1;
	up[root]=0;
	dwn[root]=A[root];
	h[root]=0;
	v1={root};
	for (int v:G[root]) if (!dead[v]){
		dfs2(v, root);
		Calc(v2, -1);
		for (int i:v2) v1.pb(i);
		v2.clear();
	}
	Calc(v1, +1);
	
//	debug("done")
//	cerr<<'\n';
	
	for (int v:G[root]) if (!dead[v]) Decompose(v);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>Y>>K>>X;
	tav[0]=1;
	for (int i=1; i<MAXN; i++) tav[i]=tav[i-1]*K%Y;
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int i=1; i<n; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	Decompose(1);
	for (int v=1; v<=n; v++){
		ans+=g[v]*(n-g[v])*2;
		ans+=f[v]*(n-f[v])*2;
		ans+=f[v]*(n-g[v]);
		ans+=g[v]*(n-f[v]);
	}
	ans/=2;
	ans=n*n*n-ans;
	cout<<ans<<'\n';
	
	return 0;
}
/*
5 2 1 1
1 0 0 0 0
1 2
1 5
5 3
1 4

*/