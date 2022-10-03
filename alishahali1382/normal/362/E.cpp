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
const int MAXM=300010, N=53, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[N][N], head[N], Q[N], dist[N], par[N], inq[N];
int to[MAXM], cap[MAXM], cost[MAXM], prv[MAXM], L, R, M;

inline void add_edge(int u, int v, int c, int w){
	to[M]=v, cap[M]=c, cost[M]=w, prv[M]=head[u], head[u]=M++;
	to[M]=u, cap[M]=0, cost[M]=-w, prv[M]=head[v], head[v]=M++;
}
bool Flow(int src, int snk){
	memset(dist, 63, sizeof(dist));
	L=R=0;
	dist[Q[R++]=src]=0;
	while (L^R){
		int v=Q[L++];
		if (L==N) L=0;
		inq[v]=0;
		for (int i=head[v]; ~i; i=prv[i]) if (cap[i]){
			int u=to[i];
			if (dist[u]>dist[v]+cost[i]){
				dist[u]=dist[v]+cost[i];
				par[u]=i;
				if (!inq[u]){
					inq[u]=1;
					Q[R++]=u;
					if (R==N) R=0;
				}
			}
		}
	}
	if (dist[snk]>k) return 0;
	int v=snk, flow=inf;
	if (dist[snk]) flow=k/dist[snk];
	while (v^src){
		int i=par[v];
		flow=min(flow, cap[i]);
		v=to[i^1];
	}
	v=snk;
	while (v^src){
		int i=par[v];
		cap[i]-=flow;
		cap[i^1]+=flow;
		v=to[i^1];
	}
	k-=dist[snk]*flow;
	ans+=flow;
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	memset(head, -1, sizeof(head));
	cin>>n>>k;
	for (int i=1; i<=n; i++) for (int j=1; j<=n; j++){
		cin>>A[i][j];
		if (A[i][j]){
			add_edge(i, j, A[i][j], 0);
			add_edge(i, j, k, 1);
		}
	}
	while (Flow(1, n)) ;
	cout<<ans<<"\n";
	
	return 0;
}
/*
1 0
0

*/