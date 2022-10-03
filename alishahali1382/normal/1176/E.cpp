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

int T, n, m, k, u, v, x, y, t, a, b, ans;
int h[MAXN];
vector<int> G[MAXN];
vector<int> out[2];

void dfs(int node, int par){
	h[node]=h[par]+1;
	for (int v:G[node]) if (!h[v]) dfs(v, node);
}

void solve(){
	cin>>n>>m;
	for (int i=1; i<=n; ++i){
		h[i]=0;
		G[i].clear();
	}
	while (m--){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs(1, 1);
	out[0].clear();
	out[1].clear();
	for (int i=1; i<=n; i++) out[h[i]&1].pb(i);
	ans=0;
	if (out[1].size()<out[0].size()) ans=1;
	cout<<out[ans].size()<<'\n';
	for (int v:out[ans]) cout<<v<<' ';cout<<'\n';
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>T;
	while (T--) solve();
	
	
	return 0;
}