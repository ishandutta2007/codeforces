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

ll n, m, u, v, w, x, a, b, c, cnt, mst, t;
pii E[MAXN];
int W[MAXN];
int par[MAXN][20];
ll mx[MAXN][20];
int lv[MAXN];
int ind[MAXN];
ll ans[MAXN];
DSU dsu;
vector<pii> G[MAXN];

void dfs(int node, int p){
	lv[node]=lv[p]+1;
	par[node][0]=p;
	for (int i=1; i<20; i++) par[node][i]=par[par[node][i-1]][i-1];
	for (int i=1; i<20; i++) mx[node][i]=max(mx[node][i-1], mx[par[node][i-1]][i-1]);
	for (pii pp:G[node]){
		int i=pp.first, w=pp.second;
		if (i==p) continue ;
		mx[i][0]=w;
		dfs(i, node);
	}
}

int getp(int x, int y){
	if (y==0) return x;
	return getp(par[x][__builtin_ctz(y)], y-(y&(-y)));
}

int lca(int x, int y){
	if (lv[x]>lv[y]) swap(x, y);
	y=getp(y, lv[y]-lv[x]);
	//cerr<<"lca "<<x<<' '<<y<<endl;
	for (int i=19; i>=0; i--){
		if (par[x][i]==par[y][i]) continue ;
		x=par[x][i];
		y=par[y][i];
	}
	if (x==y) return x;
	return par[x][0];
}

ll getmx(int x, int y){
	if (y==0) return 0;
	return max(mx[x][__builtin_ctz(y)], getmx(par[x][__builtin_ctz(y)], y-(y&(-y))));
}

ll calc(int u, int v){
	int l=lca(u, v);
	return max(getmx(u, lv[u]-lv[l]), getmx(v, lv[v]-lv[l]));
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
	vector<int> vec;
	for (int j=0; j<=m && t<n-1; j++){
		int i=ind[j];
		if (!j || W[vec[0]]==W[i]) vec.pb(i);
		else{
			for (int x:vec){
				int u=E[x].first, v=E[x].second;
				if (dsu.get(u)!=dsu.get(v)) ans[x]=-1;
			}
			for (int x:vec){
				int u=E[x].first, v=E[x].second, w=W[x];
				if (dsu.get(u)==dsu.get(v)) continue ;
				dsu.join(u, v);
				t++;
				G[u].pb({v, w});
				G[v].pb({u, w});
				mst+=w;
			}
			vec.clear();
			vec.pb(i);
		}
	}
	for (int i=0; i<m; i++) if (ans[i]==-1) ans[i]=mst;
	//debug(mst);
	dfs(1, 0);
	for (int i=0; i<m; i++){
		if (ans[i]) continue ;
		int u=E[i].first, v=E[i].second, w=W[i];
		ans[i]=mst+w-calc(u, v);
	}
	for (int i=0; i<m; i++) cout<<ans[i]<<'\n';
	
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