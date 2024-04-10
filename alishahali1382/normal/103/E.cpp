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
const int N=305, FN=N*2;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[N][N], match[N], W[N];
int cap[FN][FN], dist[FN], Q[FN], pnt[FN], L, R;

bool bfs(int src, int snk){
	memset(dist, 63, sizeof(dist));
	L=R=0;
	dist[Q[R++]=src]=0;
	while (L<R){
		int v=Q[L++];
		for (int u=0; u<FN; u++) if (cap[v][u] && dist[v]+1<dist[u]){
			dist[u]=dist[v]+1;
			Q[R++]=u;
		}
	}
	return dist[snk]<inf;
}
int dfs(int node, int snk, int flow=inf){
	if (node==snk) return flow;
	int res=0;
	for (int &v=pnt[node]; v<FN; v++) if (cap[node][v] && dist[node]+1==dist[v]){
		int val=dfs(v, snk, min(flow, cap[node][v]));
		res+=val;
		flow-=val;
		cap[node][v]-=val;
		cap[v][node]+=val;
		if (!flow) break ;
	}
	return res;
}
int Flow(int src, int snk){
	int res=0, flow;
	while (bfs(src, snk)){
		memset(pnt, 0, sizeof(pnt));
		while (flow=dfs(src, snk)) res+=flow;
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++){
		cap[0][i]++;
		cap[i+n][2*n+1]++;
		cin>>m;
		while (m--){
			cin>>x;
			A[i][x]=1;
			cap[i][n+x]++;
		}
	}
	assert(Flow(0, 2*n+1)==n);
	for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) if (cap[i+n][j]) match[i]=j;
	memset(cap, 0, sizeof(cap));
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++) if (A[i][j]) cap[i][match[j]]=inf;
		cin>>W[i]; W[i]*=-1;
		if (W[i]>0) ans+=W[i], cap[0][i]=W[i];
		else cap[i][n+1]=-W[i];
	}
	cout<<Flow(0, n+1)-ans<<"\n";
	
	return 0;
}