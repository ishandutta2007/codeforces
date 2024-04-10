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
const int MAXN = 500010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
ll dp[MAXN][2];
vector<pii> G[MAXN];
vector<ll> vec;

void dfs(int node, int par){
	dp[node][0]=dp[node][1]=0;
	for (pii p:G[node]) if (p.first!=par) dfs(p.first, node);
	vec.clear();
	ll val=0;
	for (pii p:G[node]) if (p.first!=par){
		int v=p.first;
		val+=dp[v][0];
		ll tmp=p.second+dp[v][1]-dp[v][0];
		if (tmp>0) vec.pb(tmp);
	}
	sort(all(vec));
	reverse(all(vec));
	for (int i=0; i<min(k, (ll)vec.size()); i++) dp[node][0]+=vec[i];
	for (int i=0; i<min(k-1, (ll)vec.size()); i++) dp[node][1]+=vec[i];
	
	dp[node][0]=max(dp[node][0], dp[node][1]);
	dp[node][0]+=val;
	dp[node][1]+=val;
	//debug2(node, val)
	//cerr<<node<<"  "<<dp[node][0]<<' '<<dp[node][1]<<'\n';
}

void solve(){
	cin>>n>>k;
	for (int i=1; i<=n; i++) G[i].clear();
	for (int i=1; i<n; i++){
		cin>>u>>v>>x;
		G[u].pb({v, x});
		G[v].pb({u, x});
	}
	dfs(1, 1);
	cout<<dp[1][0]<<'\n';
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;cin>>T;
	while (T--) solve();
	
	return 0;
}
/*
1
7 2
1 2 5
1 3 4
1 4 2
2 5 1
2 6 2
4 7 3

*/