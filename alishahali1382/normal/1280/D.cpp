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
const int MAXN = 3010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
ll A[MAXN];
int sz[MAXN];
pll dp[MAXN][MAXN];
pll dpp[MAXN];
vector<int> G[MAXN];
// AliShahali1382

void dfs(int node, int par){
	sz[node]=1;
	dp[node][0]={0, A[node]};
	for (int v:G[node]) if (v!=par){
		dfs(v, node);
		for (int i=0; i<sz[node]; i++) dpp[i]=dp[node][i], dp[node][i]={0, -INF};
		for (int i=0; i<sz[node]; i++) for (int j=0; j<sz[v]; j++){
			dp[node][i+j]=max(dp[node][i+j], {dpp[i].first+dp[v][j].first, dpp[i].second+dp[v][j].second});
			dp[node][i+j+1]=max(dp[node][i+j+1], {dpp[i].first+dp[v][j].first+(dp[v][j].second>0), dpp[i].second});
		}
		sz[node]+=sz[v];
	}
}

void solve(){
	cin>>n>>m;
	for (int i=1; i<=n; i++) for (int j=0; j<m; j++) dp[i][j]={0, -INF};
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int i=1; i<=n; i++) cin>>x, A[i]=x-A[i], G[i].clear();
	for (int i=1; i<n; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	//for (int i=1; i<=n; i++) debug2(i, A[i])
	dfs(1, 1);
	cout<<dp[1][m-1].first+(dp[1][m-1].second>0)<<'\n';
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	cin>>T;
	while (T--) solve();
	/*
	debugp(dp[1][1])
	debugp(dp[2][1])
	debugp(dp[2][0])
	*/
	return 0;
}
/*
1
5 2
3 0 1 0 3
0 2 0 2 0
1 2
2 3
3 4
4 5


*/