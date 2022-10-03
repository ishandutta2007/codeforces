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
#define debug(x) cerr<<#x<<'='<<x<<endl;
#define debugp(x) cerr<<#x<<"= {"<<x.first<<", "<<x.second<<"}"<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 2010;

struct DSU{
	int par[MAXN];
	int sz[MAXN];
	DSU(){
		for (int i=1; i<MAXN; i++) par[i]=i;
		for (int i=1; i<MAXN; i++) sz[i]=1;
	}
	int get(int x){
		if (par[x]==x) return x;
		return par[x]=get(par[x]);
	}
	void join(int x, int y){
		x=get(x);
		y=get(y);
		if (x==y) return ;
		if (sz[x]>sz[y]) swap(x, y);
		par[x]=y;
		sz[y]+=sz[x];
	}
} dsu;

int n, m, k, u, v, x, y, t, a, b, ans, out, cnt;
int A[MAXN];
int C[MAXN];
int sz[MAXN];
int lv[MAXN];
bitset<MAXN> dp;
bool mark[MAXN];
pii E[MAXN];
vector<int> origin[MAXN];
vector<int> G[MAXN];

int bridge(int node, int par){
	int res=lv[node]=lv[par]+1;
	for (int v:origin[node]){
		if (v==par) continue ;
		if (lv[v]) res=min(res, lv[v]);
		else res=min(res, bridge(v, node));
	}
	if (!par) return res;
	if (res<=lv[par]) dsu.join(node, par);
	else E[cnt++]={node, par};
	
	return res;
}
int dfs(int node, int par){
	sz[node]=dsu.sz[node];
	for (int v:G[node]) if (v!=par) sz[node]+=dfs(v, node);
	return sz[node];
}
void knapsack(int t){
	memset(C, 0, sizeof(C));
	dp=1;
	for (int i=0; i<t; i++) if (A[i]>=n/2){
		dp[A[i]]=1;
		return ;
	}
	for (int i=0; i<t; i++) C[A[i]]++;
	for (int i=1; i<n; i++){
		if (!C[i]) continue ;
		C[i]--;
		C[2*i]+=C[i]/2;
		C[i]%=2;
		C[i]++;
		for (int j=0; j<C[i]; j++) dp|=dp<<i;
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	while (m--){
		cin>>u>>v;
		origin[u].pb(v);
		origin[v].pb(u);
	}
	bridge(1, 0);
	for (int i=0; i<cnt; i++){
		int u=dsu.get(E[i].first),  v=dsu.get(E[i].second);
		G[u].pb(v);
		G[v].pb(u);
	}
	for (int i=1; i<=n; i++){
		if (dsu.get(i)!=i) continue ;
		memset(sz, 0, sizeof(sz));
		t=0;
		dfs(i, 0);
		for (int j:G[i]) A[t++]=sz[j];
		knapsack(t);
		int tmp=0;
		for (int j=0; j<n; j++) if (dp[j]) tmp=max(tmp, j*(n-j-dsu.sz[i]));
		for (int j=1; j<=n; j++) if (dsu.get(j)==j) tmp+=sz[j]*dsu.sz[j];
		ans=max(ans, tmp);
	}
	cout<<ans<<endl;
	
	return 0;
}
/*
          .---.                                                                     .---.              ...-'  |`. ..-'''-.       / .--. \        .-''-.
          |   |.--.                       .                     .                   |   |.--.          |      |  |\.-'''\ \     ' '    ' '     .' .-.  )
          |   ||__|                     .'|                   .'|                   |   ||__|          ....   |  |       | |    \ \    / /    / .'  / /
          |   |.--.                    <  |                  <  |                   |   |.--.            -|   |  |    __/ /      `.`'--.'    (_/   / /
    __    |   ||  |                     | |             __    | |             __    |   ||  |             |   |  |   |_  '.      / `'-. `.        / /
 .:--.'.  |   ||  |                 _   | | .'''-.   .:--.'.  | | .'''-.   .:--.'.  |   ||  |          ...'   `--'      `.  \   ' /    `. \      / /
/ |   \ | |   ||  |               .' |  | |/.'''. \ / |   \ | | |/.'''. \ / |   \ | |   ||  |          |         |`.      \ '. / /       \ '    . '
`" __ | | |   ||  |              .   | /|  /    | | `" __ | | |  /    | | `" __ | | |   ||  |          ` --------\ |       , || |         | |  / /    _.-')
 .'.''| | |   ||__|            .'.'| |//| |     | |  .'.''| | | |     | |  .'.''| | |   ||__|           `---------'        | || |         | |.' '  _.'.-''
/ /   | |_'---'              .'.'.-'  / | |     | | / /   | |_| |     | | / /   | |_'---'                                 / ,' \ \       / //  /.-'_.'
\ \._,\ '/                   .'   \_.'  | '.    | '.\ \._,\ '/| '.    | '.\ \._,\ '/                              -....--'  /   `.'-...-'.'/    _.'
 `--'  `"                               '---'   '---'`--'  `" '---'   '---'`--'  `"                               `.. __..-'       `-...-'( _.-'
*/