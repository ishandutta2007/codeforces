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
const int N=505, MAXM=200*N;

int n, m, X, u, v, x, y, t, a, b, ans;
int head[N], dist[N], Q[N], inq[N], par[N], L, R;
int to[MAXM], cap[MAXM], cost[MAXM], prv[MAXM], M;
string S, T;

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
			if (dist[v]+cost[i]<dist[u]){
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
	if (dist[snk]>=0) return 0;
	ans-=dist[snk];
	int v=snk;
	while (v^src){
		int i=par[v];
//		if (cost[i]) debug2(to[i^1], v)
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
	cin>>n>>S>>m;
	while (m--){
		cin>>T>>x;
		int sz=T.size();
		for (int i=0; i+sz<=n; i++) if (S.substr(i, sz)==T) add_edge(i, i+sz, 1, -x);
	}
	cin>>X;
	for (int i=0; i<n; i++) add_edge(i, i+1, X, 0);
	while (X--) Flow(0, n);
	cout<<ans<<"\n";
	
	return 0;
}