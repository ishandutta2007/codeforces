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
const int MAXN=3010, LOG=20;

int n, m, q, u, v, x, y, t, a, b;
int A[400001], B[400001], K[400001], ans[400001];
bool mark[MAXN][MAXN];
vector<int> G[MAXN], G2[MAXN], Q[MAXN], vec[MAXN], path;

void dfs1(bool *mark, int node){
	mark[node]=1;
	for (int v:G[node]) if (!mark[v]) dfs1(mark, v); 
}

void dfs2(int node){
	path.pb(node);
	for (int id:vec[node]) if (K[id]<=path.size()) ans[id]=path[path.size()-K[id]];
	for (int v:G2[node]) dfs2(v);
	path.pop_back();
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>q;
	while (m--){
		cin>>u>>v;
		G[u].pb(v);
//		G[v].pb(u);
	}
	for (int i=1; i<=n; i++) dfs1(mark[i], i);
	for (int i=1; i<=q; i++){
		cin>>A[i]>>B[i]>>K[i];
		ans[i]=-1;
		Q[B[i]].pb(i);
	}
	for (int v=1; v<=n; v++){
		for (int i=1; i<=n; i++) vec[i].clear(), G2[i].clear();
		for (int x=1; x<=n; x++) if (mark[x][v] && x!=v){
			int mn=inf;
			for (int y:G[x]) if (mark[y][v]) mn=min(mn, y);
			G2[mn].pb(x);
		}
		for (int id:Q[v]) vec[A[id]].pb(id);
		dfs2(v);
	}
	for (int i=1; i<=q; i++) cout<<ans[i]<<"\n";
	
	return 0;
}
/*
7 7 1
1 2
2 3
1 3
3 4
4 5
5 3
4 6
1 4 2

*/