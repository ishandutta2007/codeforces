#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
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
const int MAXN = 10, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int dp[1<<MAXN][1<<MAXN];
vector<int> G[MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>k;
	while (m--){
		cin>>u>>v;
		u--;
		v--;
		G[u].pb(v);
		G[v].pb(u);
		dp[(1<<u)|(1<<v)][(1<<u)|(1<<v)]=1;
	}
	for (int i=0; i<n; i++) dp[1<<i][1<<i]=1;
	for (int mask=7; mask<(1<<n); mask++) if (__builtin_popcount(mask)>2) for (int leaf=mask; leaf; leaf=(leaf-1)&mask){
		int v=__builtin_ctz(leaf);
		for (int par:G[v]) if ((1<<par)&(mask^leaf)) dp[mask][leaf]+=dp[mask^(1<<v)][leaf^(1<<v)] + dp[mask^(1<<v)][leaf^(1<<v)^(1<<par)];
	}
	for (int mask=0; mask<(1<<n); mask++) ans+=(__builtin_popcount(mask)==k)*dp[(1<<n)-1][mask];
	cout<<ans<<'\n';
	
	return 0;
}