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
const int MAXN = 200010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans, sum;
ll sz[MAXN];
vector<int> G[MAXN];

ll dfs_sz(int node, int par){
	for (int v:G[node]) if (v!=par) sz[node]+=dfs_sz(v, node);
	sum+=++sz[node];
	return sz[node];
}

void move(int u, int v){
	sum-=sz[u]+sz[v];
	sz[u]-=sz[v];
	sz[v]+=sz[u];
	sum+=sz[u]+sz[v];
}

void dfs(int node, int par){
	ans=max(ans, sum);
	for (int v:G[node]) if (v!=par){
		move(node, v);
		dfs(v, node);
		move(v, node);
	}
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
	dfs_sz(1, 1);
	dfs(1, 1);
	cout<<ans<<'\n';
	
	return 0;
}