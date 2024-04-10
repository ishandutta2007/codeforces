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
const int MAXN=100010, LOG=20;

ll ans; // :))
int n, m, k, u, v, x, y, t, a, b, root;
int par[MAXN], sz[MAXN], P[MAXN], A[MAXN];
vector<int> G[MAXN];

int dfs1(int node, int p){
	sz[node]=1;
	for (int v:G[node]) if (v!=p) sz[node]+=dfs1(v, node);
	return sz[node];
}
int Centroid(int node, int p){
	for (int v:G[node]) if (v!=p && 2*sz[v]>n) return Centroid(v, node);
	return node;
}
void dfs2(int node, int p){
	A[t++]=node;
	for (int v:G[node]) if (v!=p) dfs2(v, node);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<n; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs1(1, 0);
	for (int i=2; i<=n; i++) ans+=2*min(sz[i], n-sz[i]);
	root=Centroid(1, 0);
	dfs1(root, 0);
	sort(all(G[root]), [](int i, int j){
		return sz[i]>sz[j];
	});
	for (int v:G[root]) dfs2(v, root);
	A[t++]=root;
	for (int i=0; i<n; i++) P[A[i]]=A[(i+n/2)%n];
	cout<<ans<<"\n";
	for (int i=1; i<=n; i++) cout<<P[i]<<" \n"[i==n];
	
	return 0;
}