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
const int mod=998244353;
const int N=405;

ll n, m, k, u, v, x, y, t, a, b;
ll ans[N][N];
int G[N][N], P[N], D[N];
vector<int> adj[N];

bool cmp(int u, int v){ return D[u]<D[v];}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	memset(G, 31, sizeof(G));
	cin>>n>>m;
	while (m--){
		cin>>x>>y;
		G[x][y]=G[y][x]=1;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	for (int i=1; i<=n; i++) G[i][i]=0, P[i]=i;
	for (int k=1; k<=n; k++) for (int i=1; i<=n; i++) for (int j=1; j<=n; j++)
		G[i][j]=min(G[i][j], G[i][k]+G[k][j]);
	
	for (int a=1; a<=n; a++) for (int b=a; b<=n; b++){
//		debug2(a, b)
		ll res=1;
		for (int v=1; v<=n; v++){
			D[v]=G[a][v]+G[b][v]-G[a][b];
//			debug2(v, D[v])
			if (D[v]&1) res=0;
			D[v]>>=1;
		}
		if (!res) continue ;
		sort(P+1, P+n+1, cmp);
		int ted=0;
		for (int i=1; i<=n; i++){
			int v=P[i];
//			debug(v)
			if (!D[v]) ted++;
			else{
				int deg=0;
				for (int u:adj[v]) if (D[u]+1==D[v]) deg++;
				res=res*deg%mod;
			}
		}
//		debug(ted)
//		cerr<<"\n";
		
		if (ted!=G[a][b]+1) res=0;
		ans[a][b]=ans[b][a]=res;
	}
	for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) cout<<ans[i][j]<<" \n"[j==n];
	
	return 0;
}