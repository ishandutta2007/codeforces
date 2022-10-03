#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
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
const int MAXN = 100010, LOG=20, PRIME=664580;

struct QUERY{
	int u, v, lca, x;
} query[MAXN];

int n, q, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
int h[MAXN];
int par[MAXN][LOG];
int sieve[10000001];
int prime[PRIME][24];
int primeid[10000001];
map<pii, int> Q[MAXN];
vector<pii> vec[MAXN];
vector<int> G[MAXN];
vector<pii> taj[MAXN];

void dfs_lca(int node){
	h[node]=h[par[node][0]]+1;
	for (int i=1; i<LOG; i++) par[node][i]=par[par[node][i-1]][i-1];
	for (int i:G[node]) if (i!=par[node][0]){
		par[i][0]=node;
		dfs_lca(i);
	}
}

int LCA(int x, int y){
	if (h[x]>h[y]) swap(x, y);
	for (int i=0; i<LOG; i++) if ((h[y]-h[x])&(1<<i)) y=par[y][i];
	for (int i=LOG-1; i>=0; i--) if (par[x][i]!=par[y][i]){
		x=par[x][i];
		y=par[y][i];
	}
	if (x!=y) x=par[x][0];
	return x;
}

void dfs_query(int node){
	for (pii p:taj[node]){
		for (int i=1; i<=p.second; i++) prime[primeid[p.first]][i]++; 
	}
	for (pii p:vec[node]) if (!Q[node].count(p)){
		int ans=0;
		for (int i=1; i<=p.second; i++) ans+=prime[primeid[p.first]][i];
		Q[node][p]=ans;
		//cerr<<node<<' '<<p.first<<' '<<p.second<<' '<<Q[node][p]<<'\n';
	}
	
	for (int v:G[node]) if (v!=par[node][0]) dfs_query(v);
	
	for (pii p:taj[node]){
		for (int i=1; i<=p.second; i++) prime[primeid[p.first]][i]--; 
	}
}

ll powmod(ll a, ll b){
	if (!b) return 1;
	if (b&1) return a*powmod(a*a%mod, b>>1)%mod;
	return powmod(a*a%mod, b>>1);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (ll i=2; i<=10000000; i++) if (!sieve[i]){
		sieve[i]=i;
		primeid[i]=t++;
		for (ll j=i*i; j<=10000000; j+=i) sieve[j]=i;
	}
	cin>>n;
	for (int i=0; i<n-1; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	par[1][0]=1;
	dfs_lca(1);
	
	for (int i=1; i<=n; i++){
		cin>>A[i];
		int tmp=A[i];
		while (tmp>1){
			int p=sieve[tmp], t=0;
			while (tmp%p==0){
				t++;
				tmp/=p;
			}
			taj[i].pb({p, t});
		}
	}
	
	cin>>q;
	for (int i=1; i<=q; i++){
		cin>>u>>v>>x;
		query[i]={u, v, LCA(u, v), x};
		
		int tmp=x;
		while (tmp>1){
			int p=sieve[tmp], t=0;
			while (tmp%p==0){
				t++;
				tmp/=p;
			}
			vec[query[i].u].pb({p, t});
			vec[query[i].v].pb({p, t});
			vec[query[i].lca].pb({p, t});
		}
	}
	
	dfs_query(1);
	
	
	for (int i=1; i<=q; i++){
		ll ans=__gcd(query[i].x, A[query[i].lca]), tmp=query[i].x;
		while (tmp>1){
			int p=sieve[tmp], t=0;
			while (tmp%p==0){
				t++;
				tmp/=p;
			}
			//debug2(query[i].u, (Q[query[i].u][{p, t}]))
			//cerr<<query[i].u<<' '<<p<<' '<<t<<' '<<Q[query[i].u][{p, t}]<<'\n';
			
			ans=ans*powmod(p, Q[query[i].u][{p, t}]+Q[query[i].v][{p, t}]-2*Q[query[i].lca][{p, t}])%mod;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
      ___           ___                            ___           ___           ___           ___           ___           ___
     /\  \         /\__\      ___                 /\  \         /\__\         /\  \         /\__\         /\  \         /\__\      ___
    /::\  \       /:/  /     /\  \               /::\  \       /:/  /        /::\  \       /:/  /        /::\  \       /:/  /     /\  \
   /:/\:\  \     /:/  /      \:\  \             /:/\ \  \     /:/__/        /:/\:\  \     /:/__/        /:/\:\  \     /:/  /      \:\  \
  /::\~\:\  \   /:/  /       /::\__\           _\:\~\ \  \   /::\  \ ___   /::\~\:\  \   /::\  \ ___   /::\~\:\  \   /:/  /       /::\__\
 /:/\:\ \:\__\ /:/__/     __/:/\/__/          /\ \:\ \ \__\ /:/\:\  /\__\ /:/\:\ \:\__\ /:/\:\  /\__\ /:/\:\ \:\__\ /:/__/     __/:/\/__/
 \/__\:\/:/  / \:\  \    /\/:/  /             \:\ \:\ \/__/ \/__\:\/:/  / \/__\:\/:/  / \/__\:\/:/  / \/__\:\/:/  / \:\  \    /\/:/  /
      \::/  /   \:\  \   \::/__/               \:\ \:\__\        \::/  /       \::/  /       \::/  /       \::/  /   \:\  \   \::/__/
      /:/  /     \:\  \   \:\__\                \:\/:/  /        /:/  /        /:/  /        /:/  /        /:/  /     \:\  \   \:\__\
     /:/  /       \:\__\   \/__/                 \::/  /        /:/  /        /:/  /        /:/  /        /:/  /       \:\__\   \/__/
     \/__/         \/__/                          \/__/         \/__/         \/__/         \/__/         \/__/         \/__/
*/