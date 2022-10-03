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
const int mod = 998244353;
const int MAXN = 4010, K=75;

ll n, m, k, u, v, x, y, t, a, b, ans;
ll C[K][K];
ll dp1[MAXN][K], ans1[K], ans2[K];
ll sum[MAXN][K];
vector<int> G[MAXN];

void Add(ll dp1[], ll dp2[], int tmp=2){
	for (int i=2; i<=k; i+=2){
		for (int j=tmp; j<=i; j+=2) dp1[i]+=dp1[i-j]*dp2[j-tmp]%mod;
		dp1[i]%=mod;
	}
}

void dfs1(int node, int par){
	for (int v:G[node]) if (v!=par) dfs1(v, node);
	for (int v:G[node]) if (v!=par) for (int j=0; j<=k; j+=2) sum[node][j]=(sum[node][j]+dp1[v][j])%mod;
	dp1[node][0]=1;
	Add(dp1[node], sum[node]);
}

void move(int u, int v){ // u --> v
	for (int j=0; j<=k; j+=2) sum[u][j]-=dp1[v][j];
	memset(dp1[u], 0, sizeof(dp1[u]));
	dp1[u][0]=1;
	Add(dp1[u], sum[u]);
	
	for (int j=0; j<=k; j+=2) sum[v][j]+=dp1[u][j];
	memset(dp1[v], 0, sizeof(dp1[v]));
	dp1[v][0]=1;
	Add(dp1[v], sum[v]);
}

void dfs2(int node, int par){
	for (int j=0; j<=k; j+=2) ans1[j]+=dp1[node][j];
	for (int v:G[node]) if (v!=par){
		move(node, v);
		dfs2(v, node);
		move(v, node);
	}
}

void solve(){
	for (int i=1; i<n; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs1(1, 1);
	dfs2(1, 1);
	for (int j=0; j<=k; j+=2) ans1[j]%=mod;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	C[0][0]=1;
	for (int i=1; i<K; i++){
		C[i][0]=1;
		for (int j=1; j<=i; j++) C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	cin>>n>>m>>k;
	if (k&1) kill(0)
	solve();
	
	swap(n, m);
	swap(ans1, ans2);
	for (int i=0; i<MAXN; i++) G[i].clear();
	memset(dp1, 0, sizeof(dp1));
	memset(sum, 0, sizeof(sum));
	solve();
	
	for (int i=0; i<K; i++) ans+=(ans1[i]*ans2[k-i]%mod)*C[k][i]%mod;
	ans%=mod;
	cout<<ans<<'\n';
	
	return 0;
}