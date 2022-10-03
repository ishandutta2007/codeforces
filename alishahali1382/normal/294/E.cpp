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
const ll INF=100000000000000100LL;
const int mod = 1000000007;
const int MAXN = 5010, LOG=20;

struct edge{
	int u, v, w;
} E[MAXN];

ll n, m, k, u, v, x, y, t, a, b, ans=INF;
ll sz[MAXN];
vector<int> G[MAXN];

int dfs(int node, int par){
	sz[node]=1;
	for (int v:G[node]) if (v!=par) sz[node]+=dfs(v, node);
	return sz[node];
}

int centroid(int node, int par, int n){
	for (int i:G[node]) if (i!=par && sz[i]*2>n) return centroid(i, node, n);
	return node; 
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<n; i++) cin>>E[i].u>>E[i].v>>E[i].w;
	for (int i=1; i<n; i++){
		for (int j=1; j<=n; j++) G[j].clear();
		for (int j=1; j<n; j++) if (i!=j){
			G[E[j].u].pb(E[j].v);
			G[E[j].v].pb(E[j].u);
		}
		int u=E[i].u, v=E[i].v;
		dfs(u, u);
		dfs(v, v);
		
		//debug2(u, v)
		u=centroid(u, u, sz[u]);
		v=centroid(v, v, sz[v]);
		//debug2(u, v)
		
		G[u].pb(v);
		G[v].pb(u);
		dfs(1, 1);
		ll res=0;
		for (int j=1; j<n; j++) if (i!=j){
			if (sz[E[j].u]>sz[E[j].v]) swap(E[j].u, E[j].v);
			//debug2(sz[E[j].u], sz[E[j].v])
			//debug2(sz[E[j].u], n-sz[E[j].u])
			res+=E[j].w*sz[E[j].u]*(n-sz[E[j].u]);
		}
		if (sz[u]>sz[v]) swap(u, v);
		res+=E[i].w*sz[u]*(n-sz[u]);
		ans=min(ans, res);
	}
	cout<<ans<<'\n';
	
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