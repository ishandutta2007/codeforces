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
const int MAXN=2010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int E[MAXN][3];
int U[MAXN*4], V[MAXN*4], W[MAXN*4], M;
int col[MAXN], dist[MAXN];
int F[MAXN][MAXN];
int A[MAXN];
vector<int> G[MAXN];

bool dfs(int node, int c){
	col[node]=c;
	for (int v:G[node]){
		if (col[v]==c || (!col[v] && !dfs(v, 3-c))) return 0;
	}
	return 1;
}
inline void add_edge(int u, int v, int w){
	U[M]=u;
	V[M]=v;
	W[M++]=w;
	F[u][v]=min(F[u][v], w);
}
inline bool relax(int v, int d){
	if (dist[v]>d){
		dist[v]=d;
		return 1;
	}
	return 0;
}
inline bool is_ok(int u, int v, int w){
	return F[v][u]-w>=0;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=m; i++){
		cin>>u>>v>>b;
		G[u].pb(v);
		G[v].pb(u);
		E[i][0]=u, E[i][1]=v, E[i][2]=b;
	}
	if (!dfs(1, 1)) kill("NO")
	memset(F, 63, sizeof(F));
	for (int i=1; i<=n; i++) F[i][i]=0;
	for (int i=1; i<=m; i++){
		u=E[i][0], v=E[i][1], b=E[i][2];
		if (b==1){
			if (col[u]==1){
				// col[v]=2
				add_edge(u, v, 1);
				add_edge(v, u, -1);
			}
			else{
				add_edge(u, v, 0);
				add_edge(v, u, 0);	
			}
			continue ;
		}
		if (col[u]==2) swap(u, v);
		add_edge(u, v, 1);
		add_edge(v, u, 0);
	}
	
	memset(dist, 63, sizeof(dist));
	dist[1]=0;
	for (int i=1; i<=n; i++){
		for (int j=0; j<M; j++){
			if (relax(V[j], dist[U[j]]+W[j]) && i==n) kill("NO")
		}
	}
	
	for (int k=1; k<=n; k++) for (int i=1; i<=n; i++) for (int j=1; j<=n; j++)
		F[i][j]=min(F[i][j], F[i][k] + F[k][j]);
	
	int uu=0, vv=0, good=1;
	while (good--){
		debug(ans)
		ans++;
		for (int u=1; u<=n && !good; u++) for (int v=1; v<=n && !good; v++){
			if (is_ok(v, u, (ans-(col[v]==1)+(col[u]==1)+1)/2)){
				good=1;
				uu=u;
				vv=v;
			}
		}
	}
	ans--;
	add_edge(vv, uu, -((ans-(col[vv]==1)+(col[uu]==1)+1)/2));
	for (int i=1; i<=n; i++){
		for (int j=0; j<M; j++){
			if (relax(V[j], dist[U[j]]+W[j]) && i==n) cout<<1/0;
		}
	}
	
	
	
	for (int i=1; i<=n; i++){
		if (col[i]==1) A[i]=2*dist[i]+1;
		if (col[i]==2) A[i]=2*dist[i];		
	}
	debug(ans)
	ans=(*max_element(A+1, A+n+1))-(*min_element(A+1, A+n+1));
	debug(ans)
	cout<<"YES\n"<<ans<<"\n";
	for (int i=1; i<=n; i++) cout<<A[i]+ans<<" \n"[i==n];
	
	return 0;
}