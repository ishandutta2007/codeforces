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
const int MAXN = 110;

ll n, m, k, u, v, x, y, t, a, b;
ll C[MAXN][MAXN], tav[MAXN];
int sz[MAXN];
ll dp[MAXN][MAXN][MAXN];  // v  cnt   sz
ll dpp[MAXN][MAXN];
ll ans[MAXN];
vector<int> G[MAXN];

void dfs(int node, int par){
	dp[node][1][1]=1;
	sz[node]=1;
	for (int v:G[node]) if (v!=par){
		dfs(v, node);
		for (int i=1; i<=sz[node]; i++) for (int j=1; j<=sz[node]; j++) dpp[i][j]=dp[node][i][j], dp[node][i][j]=0;
		for (int c1=1; c1<=sz[node]; c1++) for (int s1=1; s1<=sz[node]; s1++){
			for (int c2=1; c2<=sz[v]; c2++) for (int s2=1; s2<=sz[v]; s2++){
				dp[node][c1+c2][s1]=(dp[node][c1+c2][s1] + dpp[c1][s1]*(dp[v][c2][s2]*s2%mod))%mod;
				dp[node][c1+c2-1][s1+s2]=(dp[node][c1+c2-1][s1+s2] + dpp[c1][s1]*dp[v][c2][s2])%mod;
			}
		}
		sz[node]+=sz[v];
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i=0; i<MAXN; i++){
		C[i][0]=C[i][i]=1;
		for (int j=1; j<i; j++) C[i][j]=(C[i-1][j] + C[i-1][j-1])%mod;
	}
	cin>>n;
	for (int i=1; i<n; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	
	tav[0]=1;
	for (int i=1; i<MAXN; i++) tav[i]=tav[i-1]*n%mod;
	
	dfs(1, 1);
	for (int c=1; c<=n; c++) for (int s=1; s<=n; s++) ans[n-c]=(ans[n-c] + dp[1][c][s]*s)%mod;
	for (int c=2; c<=n; c++) ans[n-c]=ans[n-c]*tav[c-2]%mod;
	ans[n-1]=1;
	for (int i=n-2; i>=0; i--){
		for (int j=i+1; j<n; j++) ans[i]-=ans[j]*C[j][i]%mod;
		ans[i]%=mod;
		if (ans[i]<0) ans[i]+=mod;
	}
	for (int i=0; i<n; i++) cout<<ans[i]<<' ';
	
	return 0;
}