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
#define SZ(x) ((int)x.size())
#define kill(x) return cout<<x<<'\n', 0;

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=300010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int par[MAXN], h[MAXN], A[MAXN], B[MAXN];
vector<int> G[MAXN], path[MAXN];
vector<pii> Q[MAXN];

int getpar(int x){ return (par[x]==x?x:par[x]=getpar(par[x]));}
void dfs(int node){
	for (int v:G[node]) if (v!=par[node]){
		h[v]=h[node]+1;
		par[v]=node;
		dfs(v);
	}
}
void GetPath(int x, int y, vector<int> &vec){
	vector<int> X, Y;
	while (x!=y){
		if (h[x]>h[y]){
			X.pb(x);
			x=par[x];
		}
		else{
			Y.pb(y);
			y=par[y];
		}
	}
	reverse(all(Y));
	for (int x:X) vec.pb(x);
	vec.pb(x);
	for (int x:Y) vec.pb(x);
}
void Go(int node){
	while (SZ(Q[node]) && SZ(path[Q[node].back().second])) Q[node].pop_back();
	if (Q[node].empty()) return ;
	pii p=Q[node].back();
	Q[node].pop_back();
	GetPath(node, p.first, path[p.second]);
	Go(p.first);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	iota(par+1, par+n+1, 1);
	while (m--){
		cin>>u>>v;
		if (getpar(u)==getpar(v)) continue ;
		par[getpar(u)]=getpar(v);
		G[u].pb(v);
		G[v].pb(u);
	}
	par[1]=0;
	dfs(1);
	cin>>m;
	for (int i=1; i<=m; i++){
		cin>>A[i]>>B[i];
		Q[A[i]].pb({B[i], i});
		Q[B[i]].pb({A[i], i});
	}
	int ted=0;
	for (int i=1; i<=n; i++) ted+=(SZ(Q[i])&1);
	if (ted){
		cout<<"NO\n";
		cout<<ted/2<<"\n";
		return 0;
	}
	for (int i=1; i<=n; i++) while (SZ(Q[i])) Go(i);
	cout<<"YES\n";
	for (int i=1; i<=m; i++){
		if (path[i][0]!=A[i]) reverse(all(path[i]));
		cout<<SZ(path[i])<<"\n";
		for (int v:path[i]) cout<<v<<" ";
		cout<<"\n";
	}
	
	return 0;
}