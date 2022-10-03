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
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 200010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN], sz[MAXN];
bool dead[MAXN];
ll phi[MAXN], inv[MAXN], f[MAXN], val[MAXN];
short mob[MAXN];
ll sum[MAXN];
vector<int> G[MAXN], D[MAXN];

int _mod(int x){
	if (x>=mod) x-=mod;
	if (x<0) x+=mod;
	return x;
}

void add(int x, int w){
	for (int d:D[x]) sum[d]=_mod(sum[d]+w*phi[x]);
}

ll get(int x){
	ll res=0;
	//for (int d:D[x]) for (int dd:D[x/d]) res=(res + f[d]*mob[dd]*sum[d*dd])%mod; 
	for (int d:D[x]) res=(res+val[d]*sum[d])%mod;
	return res*phi[x]%mod;
}

int dfs1(int node, int par){
	sz[node]=1;
	for (int v:G[node]) if (!dead[v] && v!=par) sz[node]+=dfs1(v, node);
	return sz[node];
}

int Centroid(int node, int par, int n){
	for (int v:G[node]) if (v!=par && !dead[v] && 2*sz[v]>n) return Centroid(v, node, n);
	return node;
}

void dfs2(int node, int par, int h){
	ans+=get(node)*h%mod;
	for (int v:G[node]) if (v!=par && !dead[v]) dfs2(v, node, h+1);
}

void dfs3(int node, int par, int h, int w){
	add(node, w);
	for (int v:G[node]) if (v!=par && !dead[v]) dfs3(v, node, h+1, w);
}

void Decompose(int v){
	int root=Centroid(v, v, dfs1(v, v));
	dead[root]=1;
	add(root, +1);
	for (int v:G[root]) if (!dead[v]){
		dfs2(v, root, 1);
		dfs3(v, root, 1, +1);
	}
	add(root, -1);
	for (int v:G[root]) if (!dead[v]){
		dfs3(v, root, 1, -1);
		dfs2(v, root, 1);
	}
	
	for (int v:G[root]) if (!dead[v]) Decompose(v);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	mob[1]=1;
	for (int i=1; i<MAXN; i++){
		phi[i]+=i;
		for (int j=i+i; j<MAXN; j+=i) phi[j]-=phi[i], mob[j]-=mob[i];
	}
	inv[1]=1;
	for (int i=2; i<MAXN; i++) inv[i]=mod-(mod/i)*inv[mod%i]%mod;
	for (int i=1; i<MAXN; i++) f[i]=i*inv[phi[i]]%mod;
	for (int i=1; i<MAXN; i++) for (int j=i; j<MAXN; j+=i) D[j].pb(i);
	for (int i=1; i<MAXN; i++) for (int j=1; i*j<MAXN; j++) val[i*j]=_mod(val[i*j]+f[i]*mob[j]);
	
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int i=1; i<n; i++){
		cin>>u>>v;
		u=A[u];
		v=A[v];
		G[u].pb(v);
		G[v].pb(u);
	}
	Decompose(1);
	//debug(ans)
	ans=ans*2%mod;
	if (ans<0) ans+=mod;
	cout<<(ans*inv[n]%mod)*inv[n-1]%mod<<'\n';
	
	return 0;
}