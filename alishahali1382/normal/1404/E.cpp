#include <bits/stdc++.h>
#pragma GCC optimize("O2")

using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<"="<<x<<"\n";
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"}= {"<<x<<", "<<y<<"}\n";
#define debugp(p) cerr<<#p<<"={"<<p.first<<", "<<p.second<<"}\n";
#define debugv(v) {cerr<<#v<<": ";for (auto abcde:v) cerr<<abcde<<", ";cerr<<"\n";}
#define kill(x) return cout<<x<<"\n", 0;
#define pb push_back
#define all(x) x.begin(), x.end()

const int inf=1000000010;
const ll INF=1000000000000000010ll;
const int mod=1000000007;
const int N=205, MAXN=2*N*N;

int n, m, k, x, y, u, v, a, b, ans;
char A[N][N];
int R[N][N], D[N][N], V, VV;
int match[MAXN], dist[MAXN];
bool mark[MAXN];
vector<int> G[MAXN];
queue<int> Q;

void addedge(int u, int v){
	if (!u || !v) return ;
	//debug2(u, v)
	G[u].pb(v);
	G[v].pb(u);
}
bool BFS(){
	memset(dist, 63, sizeof(dist));
	while (Q.size()) Q.pop();
	for (int i=1; i<=V; i++) if (!match[i]) dist[i]=0, Q.push(i);
	while (Q.size()){
		int v=Q.front();
		Q.pop();
		if (v>V){
			if (!match[v]) return 1;
			if (dist[v]+1<dist[match[v]]){
				dist[match[v]]=dist[v]+1;
				Q.push(match[v]);
			}
			continue ;
		}
		for (int u:G[v]){
			if (dist[v]+1<dist[u]){
				dist[u]=dist[v]+1;
				Q.push(u);
			}
		}
	}
	return 0;
}
bool dfs(int node){
	mark[node]=1;
	for (int v:G[node]) if (dist[node]+1==dist[v]){
		if (!match[v] || (!mark[match[v]] && dfs(match[v]))){
			match[node]=v;
			match[v]=node;
			return 1;
		}
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) cin>>A[i][j], ans+=(A[i][j]=='#');
	for (int i=1; i<=n; i++) for (int j=1; j<m; j++)
		if (A[i][j]=='#' && A[i][j+1]=='#') R[i][j]=++V;
	VV=V;
	for (int i=1; i<n; i++) for (int j=1; j<=m; j++)
		if (A[i][j]=='#' && A[i+1][j]=='#') D[i][j]=++VV;
	
	for (int i=1; i<n; i++) for (int j=1; j<m; j++){
		addedge(R[i][j], D[i][j]);
		addedge(R[i+1][j], D[i][j]);
		addedge(R[i][j], D[i][j+1]);
		addedge(R[i+1][j], D[i][j+1]);
	}
	ans-=VV;
	while (BFS()){
		memset(mark, 0, sizeof(mark));
		for (int i=1; i<=V; i++) if (!mark[i] && !match[i]) ans+=dfs(i);
	}
	cout<<ans<<"\n";
	
	return 0;
}
/*
2 2
#.
#.

*/