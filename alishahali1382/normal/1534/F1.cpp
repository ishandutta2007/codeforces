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
const int MAXN=400010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int col[MAXN], mark2[MAXN];
vector<int> dwn[MAXN], up[MAXN];
vector<bool> mark[MAXN];
string S[MAXN];
vector<int> G[MAXN], GR[MAXN], topol;

inline int get_id(int x, int y){ return x*m+y;}
inline void add_edge(int u, int v){
//	cerr<<u/m<<" "<<u%m<<" --> "<<v/m<<" "<<v%m<<"\n";
	G[u].pb(v);
	GR[v].pb(u);
}
void dfs1(int node){
	col[node]=-1;
	for (int v:G[node]) if (col[v]!=-1) dfs1(v);
	topol.pb(node);
}
void dfs2(int node, int cid){
	col[node]=cid;
	for (int v:GR[node]) if (col[v]==-1) dfs2(v, cid);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=0; i<n; i++){
		cin>>S[i];
		dwn[i].resize(m);
		up[i].resize(m);
		mark[i].resize(m);
	}
	for (int j=0; j<m; j++){
		for (int i=n-1; ~i; i--){
			if (S[i][j]=='#') dwn[i][j]=i;
			else if (i==n-1) dwn[i][j]=n;
			else dwn[i][j]=dwn[i+1][j];
		}
		for (int i=0; i<n; i++){
			if (S[i][j]=='.') up[i][j]=i;
			else if (!i) up[i][j]=-1;
			else up[i][j]=up[i-1][j];
		}
	}
	for (int i=0; i<n; i++) for (int j=0; j<m; j++) if (S[i][j]=='#'){
		if (i+1<n && dwn[i+1][j]<n) add_edge(get_id(i, j), get_id(dwn[i+1][j], j));
		if (i && S[i-1][j]=='#') add_edge(get_id(i, j), get_id(i-1, j));
		if (j && dwn[i][j-1]<n) add_edge(get_id(i, j), get_id(dwn[i][j-1], j-1));
		if (j+1<m && dwn[i][j+1]<n) add_edge(get_id(i, j), get_id(dwn[i][j+1], j+1));
	}
	for (int i=0; i<n*m; i++) if (S[i/m][i%m]=='#' && !col[i]) dfs1(i);//,debug(i);
	reverse(all(topol));
//	debugv(topol)
	for (int v:topol) if (col[v]==-1) dfs2(v, v), mark2[v]=1;//,debug(v);
	
	for (int i=0; i<n*m; i++) for (int j:G[i]) if (col[i]!=col[j]) mark2[col[j]]=0;
	for (int i=0; i<n*m; i++) ans+=mark2[i];
	cout<<ans<<"\n";
	
	return 0;
}
/*
5 7
#....#.
.#.....
#....#.
#....##
#.#....

3 3
#.#
...
...

*/