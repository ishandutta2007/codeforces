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
const int MAXN=500010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, X;
int P[MAXN], Q[MAXN], mark[MAXN];
int par[MAXN];
vector<int> G[MAXN];
set<int> G2[MAXN];
vector<pii> E;

void make1(int v){
	P[v]=Q[v]=++X;
}
void make_star(int v, vector<int> vec){
	vec.pb(v);
	reverse(all(vec));
	int sz=vec.size();
	for (int i=0; i<sz; i++){
		mark[vec[i]]=1;
		X++;
		P[vec[i]]=X;
		Q[vec[(i+1)%sz]]=X;
	}
}
int getpar(int x){ return (par[x]==x?x:par[x]=getpar(par[x]));}
void add_edge(int u, int v){
	if (getpar(u)==getpar(v)) return ;
	G2[u].insert(v);
	G2[v].insert(u);
	E.pb({u, v});
	par[getpar(u)]=getpar(v);
}
int Solve(){
	cin>>n>>m;
	E.clear();
	for (int i=1; i<=n; i++){
		G[i].clear();
		G2[i].clear();
		mark[i]=0;
		par[i]=i;
	}
	X=0;
	while (m--){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	for (int v=1; v<=n; v++){
		sort(all(G[v]));
		G[v].resize(unique(all(G[v]))-G[v].begin());
		if (G[v].size()==n-1){
			make1(v);
			continue ;
		}
		for (int i:G[v]) mark[i]=v;
		mark[v]=v;
		int mex=1;
		while (mark[mex]==v) mex++;
		add_edge(v, mex);
	}
	for (int i=1; i<=n; i++) mark[i]=0;
	for (pii p:E){
		int u=p.first, v=p.second;
		if (G2[u].size()>1 && G2[v].size()>1){
			G2[u].erase(v);
			G2[v].erase(u);
		}
	}
	for (int v=1; v<=n; v++) if (G[v].size()!=n-1 && !mark[v] && G2[v].size()>1){
		vector<int> vec;
		for (int i:G2[v]) vec.pb(i), mark[i]=1;
		make_star(v, vec);
	}
	for (int v=1; v<=n; v++) if (G[v].size()!=n-1 && !mark[v]){
		vector<int> vec;
		for (int i:G2[v]) vec.pb(i), mark[i]=1;
		make_star(v, vec);
	}
	for (int i=1; i<=n; i++) cout<<P[i]<<" \n"[i==n];
	for (int i=1; i<=n; i++) cout<<Q[i]<<" \n"[i==n];
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	cin>>T;
	while (T--) Solve();
	
	return 0;
}
/*
1
2 1
1 2

*/