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
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 15;

ll n, m, k, u, v, x, y, t, a, b, ans;
int deg[MAXN];
ll G[MAXN][MAXN];
ll dp[1<<MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	memset(G, 63, sizeof(G));
	cin>>n>>m;
	for (int i=0; i<n; i++) G[i][i]=0;
	while (m--){
		cin>>u>>v>>x;
		u--;
		v--;
		G[u][v]=min(G[u][v], x);
		G[v][u]=min(G[v][u], x);
		ans+=x;
		deg[u]++;
		deg[v]++;
	}
	for (int k=0; k<n; k++) for (int i=0; i<n; i++) for (int j=0; j<n; j++) G[i][j]=min(G[i][j], G[i][k] + G[k][j]);
	
	for (int mask=1; mask<(1<<n); mask++){
		int v=__builtin_ctz(mask);
		if (deg[v]%2==0) dp[mask]=dp[mask^(1<<v)];
		else{
			dp[mask]=INF;
			for (int j=0; j<n; j++) if ((mask&(1<<j)) && (deg[j]&1) && v!=j) dp[mask]=min(dp[mask], dp[mask^(1<<v)^(1<<j)] + G[v][j]);
		}
	}
	ans+=dp[(1<<n)-1];
	for (int i=0; i<n; i++) if (deg[i] && G[0][i]>INF) ans=-1;
	cout<<ans<<'\n';
	
	return 0;
}