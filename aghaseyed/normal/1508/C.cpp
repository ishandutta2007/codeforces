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
const int MAXN=200010, LOG=20;

ll mst;
int n, m, k, u, v, x, y, t, a, b, xorall, ted;
int mark[MAXN], deg[MAXN], shit;
int par[MAXN];
vector<int> G[MAXN];
vector<pair<int, pii>> E; 

int getpar(int x){ return (par[x]==x?x:par[x]=getpar(par[x]));}
int join(int x, int y){
	x=getpar(x);
	y=getpar(y);
	if (x==y) return 0;
	par[x]=y;
	return 1;
}


int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	iota(par, par+MAXN, 0);
	cin>>n>>m;
	for (int i=0; i<m; i++){
		cin>>u>>v>>x;
		xorall^=x;
		G[u].pb(v);
		G[v].pb(u);
		E.pb({x, {u, v}});
	}
	int root=1;
	for (int i=2; i<=n; i++) if (G[i].size()<G[root].size()) root=i;
	for (int v:G[root]) mark[v]=root;
	mark[root]=root;
	for (int i=1; i<=n; i++) if (mark[i]!=root){
		ted+=join(i, root);
		for (int v:G[i]) if (mark[v]==root) deg[v]++;
	}
	for (int v:G[root]){
		if (deg[v]<n-G[root].size()-1) ted+=join(root, v);
		for (int u:G[v]) mark[u]=v;
		for (int u:G[root]) if (mark[u]!=v) ted+=join(u, v);//,debug2(u, v);
	}
	
	sort(all(E));
	vector<pii> vec;
	for (auto p:E) if (join(p.second.first, p.second.second)){
		mst+=p.first;
		vec.pb(p.second);
//		debugp(p.second)
	}
//	debug(ted)
	if (n>1000 || n*(n-1)/2!=m+ted) kill(mst)
	ll res=mst+xorall;
	iota(par, par+MAXN, 0);
	for (pii p:vec) join(p.first, p.second);
	for (auto p:E) if (getpar(p.second.first)!=getpar(p.second.second))
		res=min(res, mst+p.first);
	kill(res)
	
	return 0;
}