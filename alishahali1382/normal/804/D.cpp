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
#define kill(x) return cout<<(x)<<'\n', 0;
#define kill2(x) return cout<<fixed<<setprecision(12)<<(x)<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 100010;

ll dp1[MAXN], dp2[MAXN];
ll premx[MAXN], sufmx[MAXN];
bool mark[MAXN];
vector<int> G[MAXN];

ll dfsdown(int node){
	mark[node]=1;
	for (int i:G[node]) if (!mark[i]) dp1[node]=max(dp1[node], dfsdown(i)+1);
	return dp1[node];
}
void dfsup(int node){
	mark[node]=1;
	vector<int> vec;
	vec.pb(0);
	for (int v:G[node]){
		if (mark[v]) continue ;
		vec.pb(v);
		dp2[v]=max(dp2[v], dp2[node]+1);
	}
	premx[0]=sufmx[vec.size()]=-inf;
	for (int i=1; i<vec.size(); i++) premx[i]=max(premx[i-1], dp1[vec[i]]);
	for (int i=vec.size()-1; i; i--) sufmx[i]=max(sufmx[i+1], dp1[vec[i]]);
	for (int i=1; i<vec.size(); i++) dp2[vec[i]]=max(dp2[vec[i]], max(premx[i-1], sufmx[i+1])+2);
	
	for (int v:G[node]) if (!mark[v]) dfsup(v);
}

struct DSU{
	int par[MAXN];
	DSU(){
		for (int i=1; i<MAXN; i++) par[i]=i;
	}
	int get(int x){
		if (par[x]==x) return x;
		return par[x]=get(par[x]);
	}
	void join(int x, int y){
		par[get(y)]=get(x);
	}
} dsu;

int n, m, q, u, v, x, y, t, a, b, ans;
ll D[MAXN];
vector<int> vec[MAXN];
vector<int> ps[MAXN];
unordered_map<ll, ld> mp;

int query(){
	cin>>u>>v;
	u=dsu.get(u);
	v=dsu.get(v);
	if (u==v) kill(-1);
	if (u>v) swap(u, v);
	if (vec[u].size()>vec[v].size()) swap(u, v); // sz[u] < sz[v]   ||   sz[u]==sz[v] && u<v
	ll tmp=1ll*u*MAXN+v;
	if (mp.count(tmp)) kill2(mp[tmp]);
	ll res=0, d=max(D[u], D[v]);
	int t=vec[v].size();
	for (ll da:vec[u]){
		int x=lower_bound(all(vec[v]), d-da-1)-vec[v].begin();
		res+=d*x+(da+1)*(t-x);
		res+=ps[v].back()-ps[v][x];
	}
	
	ld out=(ld)res/vec[u].size()/vec[v].size();
	kill2(mp[tmp]=out);
}


int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>q;
	while (m--){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
		dsu.join(u, v);
	}
	for (int i=1; i<=n; i++) if (!mark[i]) dfsdown(i);
	memset(mark, 0, sizeof(mark));
	for (int i=1; i<=n; i++) if (!mark[i]) dfsup(i);
	for (int i=1; i<=n; i++) D[dsu.get(i)]=max(D[dsu.get(i)], max(dp1[i], dp2[i]));
	for (int i=1; i<=n; i++) vec[dsu.get(i)].pb(max(dp1[i], dp2[i]));
	for (int i=1; i<=n; i++) sort(all(vec[i])), ps[i].pb(0);
	for (int i=1; i<=n; i++) for (int j:vec[i]) ps[i].pb(ps[i].back()+j);
	
	while (q--) query();
	
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