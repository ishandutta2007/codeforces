#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops,no-stack-protector,fast-math")

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define pb push_back
#define upd(x, y) x=max(x, y)

const int MAXN=2010;

ll n, m, k, u, v, x, y, s, t, a, b, ans;
ll A[MAXN];
ll dp[2][MAXN][MAXN];
ll dist[MAXN];
int P0[MAXN], P1[MAXN];
int koj0[MAXN], koj1[MAXN];
bool good0[MAXN], good1[MAXN];
priority_queue<pll, vector<pll>, greater<pll>> pq;
vector<pll> G[MAXN];

void dijkstra(int src){
	pq.push({dist[src]=0, src});
	while (pq.size()){
		int v=pq.top().second;
		pq.pop();
		for (pll p:G[v]) if (dist[p.first]>dist[v]+p.second)
			pq.push({dist[p.first]=dist[v]+p.second, p.first});
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>s>>t;
	for (int i=1; i<=n; i++) cin>>A[i];
	while (m--){
		cin>>u>>v>>x;
		G[u].pb({v, x});
		G[v].pb({u, x});
	}
	
	memset(dist, 63, sizeof(dist));
	dijkstra(s);
	iota(P0+1, P0+n+1, 1);
	sort(P0+1, P0+n+1, [](ll i, ll j){
		return dist[i]<dist[j];
	});
	for (int i=1; i<=n; i++) koj0[P0[i]]=i;
	for (int i=1; i<=n; i++) good0[i]=(i==n || dist[P0[i]]!=dist[P0[i+1]]);
	
	memset(dist, 63, sizeof(dist));
	dijkstra(t);
	iota(P1+1, P1+n+1, 1);
	sort(P1+1, P1+n+1, [](ll i, ll j){
		return dist[i]<dist[j];
	});
	for (int i=1; i<=n; i++) koj1[P1[i]]=i;
	for (int i=1; i<=n; i++) good1[i]=(i==n || dist[P1[i]]!=dist[P1[i+1]]);
	
	memset(dp, -31, sizeof(dp));
	for (int x=1; x<=n+1; x++) for (int j:{0, 1}) dp[j][x][n+1]=dp[j][n+1][x]=0;
	for (int x=n; x; x--) for (int y=n; y; y--){
		int v=P0[x];
		if (koj1[v]<y) dp[0][x][y]=dp[0][x+1][y];
		else{
			dp[0][x][y]=A[v] + dp[0][x+1][y];
			if (good0[x]) upd(dp[0][x][y], A[v] - dp[1][x+1][y]);
		}
		
		v=P1[y];
		if (koj0[v]<x) dp[1][x][y]=dp[1][x][y+1];
		else{
			dp[1][x][y]=A[v] + dp[1][x][y+1];
			if (good1[y]) upd(dp[1][x][y], A[v] - dp[0][x][y+1]);
		}
	}
	ans=dp[0][1][1];
	if (ans<0) cout<<"Cry\n";
	if (ans==0) cout<<"Flowers\n";
	if (ans>0) cout<<"Break a heart\n";
	
	return 0;
}