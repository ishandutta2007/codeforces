#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

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

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 1010, K=42;

int n, m, q, k, u, v, x, y, xx, yy, t, a, b, ans;
int A[MAXN][MAXN], id[MAXN][MAXN], X[MAXN*MAXN], Y[MAXN*MAXN], N;
int dist[K][MAXN*MAXN+K];
vector<pii> G[MAXN*MAXN+K];
queue<int> Q;

inline void update(int v, int w, int i){
	if (w>=dist[i][v]) return ;
	dist[i][v]=w;
	Q.push(v);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>k;
	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++){
		id[i][j]=N++;
		X[id[i][j]]=i;
		Y[id[i][j]]=j;
		cin>>A[i][j];
	}
	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++){
		/*
		if (i-1) G[id[i][j]].emplace_back(id[i-1][j], 2);
		if (j-1) G[id[i][j]].emplace_back(id[i][j-1], 2);
		if (i+1<=n) G[id[i][j]].emplace_back(id[i+1][j], 2);
		if (j+1<=m) G[id[i][j]].emplace_back(id[i][j+1], 2);
		*/
		G[id[i][j]].emplace_back(N+A[i][j], 1);
		G[N+A[i][j]].emplace_back(id[i][j], 1);
	}
	
	memset(dist, 31, sizeof(dist));
	for (int i=1; i<=k; i++){
		Q.push(N+i);
		dist[i][N+i]=0;
		while (Q.size()){
			int v=Q.front();
			Q.pop();
			
			for (pii p:G[v]) update(p.first, dist[i][v]+p.second, i);
			if (v>=N) continue ;
			
			int x=X[v], y=Y[v];
			if (x-1) update(id[x-1][y], dist[i][v]+2, i);
			if (y-1) update(id[x][y-1], dist[i][v]+2, i);
			if (x+1<=n) update(id[x+1][y], dist[i][v]+2, i);
			if (y+1<=m) update(id[x][y+1], dist[i][v]+2, i);
		}
	}
	
	cin>>q;
	while (q--){
		cin>>x>>y>>xx>>yy;
		ans=2*(abs(x-xx) + abs(y-yy));
		for (int i=1; i<=k; i++) ans=min(ans, dist[i][id[x][y]] + dist[i][id[xx][yy]]);
		cout<<ans/2<<'\n';
		
	}
	
	
	return 0;
}
/*
3 4 5
1 2 1 3
4 4 5 5
1 2 1 3
1
1 1 3 4

*/