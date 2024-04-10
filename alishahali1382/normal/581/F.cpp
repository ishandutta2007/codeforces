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
const int MAXN = 5010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, root;
int sz[MAXN];
int dp[MAXN][MAXN];
int pd[MAXN];
vector<int> G[MAXN];

void dfs(int node, int par){
	if (G[node].size()==1){
		dp[node][1]=0;
		sz[node]=1;
		return ;
	}
	dp[node][0]=0;
	for (int v:G[node]) if (v!=par){
		dfs(v, node);
		for (int i=0; i<=sz[node]; i++) pd[i]=dp[node][i], dp[node][i]=inf;
		for (int i=0; i<=sz[node]; i++) for (int j=0; j<=sz[v]; j++){
			dp[node][i+j]=min(dp[node][i+j], pd[i]+dp[v][j]);
			dp[node][i+sz[v]-j]=min(dp[node][i+sz[v]-j], pd[i]+dp[v][j]+1);
		}
		sz[node]+=sz[v];
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	if (n==2) kill(1)
	for (int i=1; i<n; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	for (root=1; G[root].size()==1; root++);
	memset(dp, 63, sizeof(dp));
	dfs(root, root);
	cout<<dp[root][sz[root]/2]<<'\n';
	
	return 0;
}