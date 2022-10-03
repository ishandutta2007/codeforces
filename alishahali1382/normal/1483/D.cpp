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
const int N=605;

ll n, m, k, u, v, x, y, t, a, b, ans;
ll G[N][N], F[N][N];
bool good[N][N];
vector<pii> adj[N], vec[N];

void itsgood(int x, int y){
	if (x>y) swap(x, y);
	if (!good[x][y]){
		good[x][y]=1;
		ans++;
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	memset(G, 31, sizeof(G));
	memset(F, 31, sizeof(F));
	while (m--){
		cin>>u>>v>>x;
		G[u][v]=G[v][u]=x;
		adj[u].pb({v, x});
		adj[v].pb({u, x});
	}
	for (int i=1; i<=n; i++) G[i][i]=0;
	for (int k=1; k<=n; k++) for (int i=1; i<=n; i++) for (int j=1; j<=n; j++)
		G[i][j]=min(G[i][j], G[i][k] + G[k][j]);
	
	cin>>m;
	while (m--){
		cin>>u>>v>>x;
		for (int i=1; i<=n; i++){
			F[u][i]=min(F[u][i], G[v][i]-x);
			F[v][i]=min(F[v][i], G[u][i]-x);
		}
	}
	for (int u=1; u<=n; u++) for (pii p:adj[u]){
		int v=p.first, w=p.second;
		for (int a=1; a<=n; a++) if (F[a][v]+w+G[u][a]<=0) itsgood(u, v);
	}
	cout<<ans<<"\n";
	
	return 0;
}