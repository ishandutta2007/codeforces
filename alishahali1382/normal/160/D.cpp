#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<x<<endl;
#define debugp(x) cerr<<#x<<"= {"<<x.first<<", "<<x.second<<"}"<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000010LL;
const int mod = 1000000007;
const int MAXN = 300010;

struct DSU{
	int par[MAXN];
	int sz[MAXN];
	DSU(){
		for (int i=0; i<MAXN; i++) par[i]=i;
		for (int i=0; i<MAXN; i++) sz[i]=1;
	}
	int get(int x){
		if (par[x]==x) return x;
		return par[x]=get(par[x]);
	}
	ll getsz(int x){
		return sz[get(x)];
	}
	
	void join(int x, int y){
		//cerr<<"join "<<x<<' '<<y<<endl;
		if (sz[get(x)]>sz[get(y)]) swap(x, y);
		sz[get(y)]+=sz[get(x)];
		par[get(x)]=get(y);
	}
};

ll n, m, u, v, w, x, a, b, c, mst, t;
pii E[MAXN];
int W[MAXN];
int ind[MAXN];
int par[MAXN];
int lv[MAXN];
bool mark[MAXN];
int ans[MAXN];
DSU dsu;
vector<pii> G[MAXN];

int dfs(int node, int edge, int p){
	par[node]=p;
	lv[node]=lv[p]+1;
	int res=MAXN;
	mark[node]=true;
	for (pii pp:G[node]){
		int i=pp.first, j=pp.second;
		if (j==edge) continue ;
		if (!mark[i]) res=min(res, dfs(i, j, node));
		else res=min(res, lv[i]);
	}
	if (lv[node]<=res) ans[edge]=1;
	return res;
}

bool cmp(int i, int j){return W[i]<W[j];}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=0; i<m; i++){
		cin>>u>>v>>W[i];
		E[i]={u, v};
		ind[i]=i;
	}
	sort(ind, ind+m, cmp);
	ind[m]=m;
	vector<int> vv, vec, v2;
	fill(ans, ans+MAXN, 2);
	for (int j=0; j<=m; j++){
		int i=ind[j];
		if (!j || W[vv[0]]==W[i]) vv.pb(i);
		else{
			for (int x:vv){
				int u=E[x].first, v=E[x].second;
				if (dsu.get(u)!=dsu.get(v)) vec.pb(x);
				else ans[x]=3;
			}
			vv.clear();
			for (int x:vec){
				int u=dsu.get(E[x].first), v=dsu.get(E[x].second);
				G[u].pb({v, x});
				G[v].pb({u, x});
				v2.pb(u);
				v2.pb(v);
			}
			for (int x:vec){
				int u=dsu.get(E[x].first), v=dsu.get(E[x].second);
				if (!mark[u]) dfs(u, -1, 0);
			}
			for (int x:vec) dsu.join(E[x].first, E[x].second);
			for (int x:v2) G[x].clear();
			for (int x:v2) lv[x]=mark[x]=0;
			vec.clear();
			v2.clear();
			vv.pb(i);
		}
	}
	string out[]={"any", "at least one", "none"};
	for (int i=0; i<m; i++) cout<<out[ans[i]-1]<<'\n';
	
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