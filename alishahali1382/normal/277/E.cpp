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
const ld eps=1e-7;
const int mod=1000000007;
const int MAXN=410, FN=2*MAXN, FM=MAXN*MAXN/2;

int n, m, k, u, v, x, y, t, a, b;
int X[MAXN], Y[MAXN];
int to[FM<<1], prv[FM<<1], cap[FM<<1], M;
int head[FN], Q[FN*100], par[FN], inq[FN], L, R;
ld dist[FN], cost[FM<<1], ans;
vector<int> G[FN];

inline void add_edge(int u, int v, int c, ld w){
	to[M]=v, cap[M]=c, cost[M]=w, G[u].pb(M++);//, prv[M]=head[u], head[u]=M++;
	to[M]=u, cap[M]=0, cost[M]=-w, G[v].pb(M++);//, prv[M]=head[v], head[v]=M++;
}
bool Flow(int src, int snk){
	fill(dist, dist+FN, inf);
	L=R=0;
	dist[Q[R++]=src]=0;
	inq[src]=1;
	bool res=0;
	while (L^R){
		int v=Q[L++];
		res|=(v==snk);
		inq[v]=0;
		for (int i:G[v]) if (cap[i]){
			int u=to[i];
			if (dist[u]>eps+dist[v]+cost[i]){
				dist[u]=dist[v]+cost[i];
				par[u]=i;
				if (!inq[u]){
					inq[u]=1;
					Q[R++]=u;
				}
			}
		}
	}
	if (!res) return 0;
	ans+=dist[snk];
	int v=snk;
	while (v^src){
		int i=par[v];
		cap[i]--;
		cap[i^1]++;
		v=to[i^1];
	}
	return 1;
}


int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	memset(head, -1, sizeof(head));
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>X[i]>>Y[i];
		add_edge(0, i<<1, 1, 0);
		add_edge(i<<1 | 1, 1, 2, 0);
	}
	for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) if (Y[i]<Y[j]){
		ld dx=X[i]-X[j], dy=Y[i]-Y[j], d=sqrt(dx*dx+dy*dy);
		add_edge(i<<1, j<<1 | 1, 1, d);
	}
	for (int i=1; i<n; i++) if (!Flow(0, 1)) kill(-1)
	cout<<setprecision(12)<<fixed<<ans<<"\n";
	
	return 0;
}