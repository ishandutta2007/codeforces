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
#define SZ(x) ((int)x.size())
#define kill(x) return cout<<x<<'\n', 0;
#define getbit(x, y) (((x)>>(y))&1)

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int N=510;

ll ans;
int n, m, k, u, v, x, y, t, a, b;
int G[N][N];
int E[N*N][3];

inline void upd(int u, int v, ll w){
	ans=min(ans, w*(G[1][u]+G[v][n]+1));
	for (int i=1; i<=n; i++){
		ans=min(ans, w*(G[v][i]+1+G[1][i]+G[i][n]+1));
	}
}

int Main(){
	cin>>n>>m;
	memset(G, 63, sizeof(G));
	for (int i=1; i<=m; i++){
		cin>>E[i][0]>>E[i][1]>>E[i][2];
		G[E[i][0]][E[i][1]]=1;
		G[E[i][1]][E[i][0]]=1;
	}
	for (int i=1; i<=n; i++) G[i][i]=0;
	for (int w=1; w<=n; w++) for (int u=1; u<=n; u++) for (int v=1; v<=n; v++)
		G[u][v]=min(G[u][v], G[u][w]+G[w][v]);
	
	ans=INF;
	for (int i=1; i<=m; i++){
		int u=E[i][0], v=E[i][1];
		ll w=E[i][2];
		upd(u, v, w);
		upd(v, u, w);
	}
	cout<<ans<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while (T--) Main();
	
	return 0;
}
/*
1
8 8
4 6 92
7 1 65
6 5 43
6 7 96
4 3 74
4 8 54
7 4 99
2 5 22

*/