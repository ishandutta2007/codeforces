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
const int mod = 998244353;
const int MAXN = 300010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
ll dp[MAXN][3];
vector<int> G[MAXN];

void dfs(int node, int par){
	dp[node][0]=dp[node][2]=1;
	for (int v:G[node]) if (v!=par){
		ll d0=dp[node][0], d1=dp[node][1], d2=dp[node][2];
		dfs(v, node);
		dp[node][0]=d0*(dp[v][0] + dp[v][1])%mod;
		dp[node][1]=(d1*dp[v][0] + d1*dp[v][1]*2 + d2*dp[v][0] + d2*dp[v][2])%mod;
		dp[node][2]=(d2*dp[v][0] + d2*dp[v][1]*2)%mod;
	}
	dp[node][2]-=dp[node][0];
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<n; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs(1, 0);
	ans=(dp[1][0] + dp[1][1])%mod;
	
	if (ans<0) ans+=mod;
	cout<<ans<<'\n';
	/*
	debug2(dp[2][0], dp[2][1])
	debug(dp[2][2])*/
	
	return 0;
}
/*
3
1 2
1 3

*/