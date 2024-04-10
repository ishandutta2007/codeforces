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
const int MAXN=100010, K=203;

ll n, m, u, v, x, y, t, a, b, ans;
ll dp[MAXN][K]; // someone is out of v's subtree
ll dpt[K], cnt[K];
ll C[K][K], Z[K][K], tav[MAXN];
int sz[MAXN], k;
vector<int> G[MAXN];

void dfs(int node, int par){
	dp[node][0]=2;
	sz[node]=1;
	for (int v:G[node]) if (v!=par){
		dfs(v, node);
		for (int i=0; i<=min(sz[node], k); i++)
			dpt[i]=dp[node][i], dp[node][i]=0;
		
		for (int i=0; i<=min(sz[node], k); i++)
			for (int j=0; j<=min(sz[v], k) && i+j<=k; j++){
				dp[node][i+j]=(dp[node][i+j] + dpt[i]*dp[v][j])%mod;
			}
		
		sz[node]+=sz[v];
	}
	for (int v:G[node]) if (v!=par){
		for (int i=1; i<=min(sz[v], k); i++) cnt[i]-=dp[v][i];
	}
	for (int i=1; i<=min(sz[node], k); i++) cnt[i]+=dp[node][i];
	
	
	for (int i=min(sz[node], k); i; i--){
		dp[node][i]=(dp[node][i] + dp[node][i-1])%mod;
	}
	dp[node][1]--;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i=0; i<K; i++){
		C[i][0]=C[i][i]=1;
		for (int j=1; j<i; j++) C[i][j]=(C[i-1][j-1] + C[i-1][j])%mod;
	}
	tav[0]=1;
	for (int i=1; i<MAXN; i++) tav[i]=tav[i-1]*2%mod;
	Z[1][1]=1;
	for (int i=2; i<K; i++) for (int j=1; j<=i; j++)
		Z[i][j]=(Z[i-1][j]+Z[i-1][j-1])*j%mod;
	
	cin>>n>>k;
	for (int i=1; i<n; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs(1, 0);
//	for (int i=1; i<=k; i++) debug2(i, cnt[i])
	for (int i=1; i<=k; i++) ans=(ans + Z[k][i]*(cnt[i]%mod))%mod;
	if (ans<0) ans+=mod;
	cout<<ans<<"\n";
	
	return 0;
}
/*
4 4
1 2
2 3
2 4

*/