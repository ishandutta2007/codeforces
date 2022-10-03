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
		if (sz[get(x)]>sz[get(y)]) swap(x, y);
		sz[get(y)]+=sz[get(x)];
		par[get(x)]=get(y);
	}
};

ll n, m, u, v, w, x, a, b, c, ans, cnt;
pii E[MAXN];
int W[MAXN];
int ind[MAXN];
ll dp[MAXN];
ll val[MAXN];
bool mark[MAXN];
DSU dsu;
vector<pii> G[MAXN];

ll dfs0(int node, int p){
	//cerr<<"dfs0 "<<node<<' '<<p<<endl;
	ll res=dsu.getsz(node);
	for (pii pp:G[node]){
		if (pp.first==p) continue ;
		res+=dfs0(pp.first, node);
	}
	return dp[node]=res;
}

void dfs(int node, ll s){
	mark[node]=true;
	for (pii p:G[node]){
		int x=p.first, i=p.second;
		if (mark[x]) continue ;
		val[i]=(s-dp[x])*dp[x];
		dfs(x, s);
	}
}

bool cmp(int i, int j){return W[i]<W[j];}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=0; i<n-1; i++){
		cin>>u>>v>>W[i];
		E[i]={u, v};
		ind[i]=i;
	}
	sort(ind, ind+n-1, cmp);
	ind[n-1]=n-1;
	vector<int> vec;
	for (int j=0; j<n; j++){
		int i=ind[j];
		int w=W[i], u=E[i].first, v=E[i].second;
		if (vec.empty() || W[vec[0]]==w) vec.pb(i);
		else{
			vector<int> v2;
			for (int x:vec){
				int a=dsu.get(E[x].first), b=dsu.get(E[x].second);
				G[a].pb({b, x});
				G[b].pb({a, x});
				v2.pb(a);
				v2.pb(b);
			}
			for (int x:v2){
				if (mark[x]) continue ;
				ll s=dfs0(x, 0);
				//debug(s);
				dfs(x, s);
			}
			
			for (int x:v2) G[x].clear();
			for (int x:v2) mark[x]=false;
			for (int x:vec) dsu.join(E[x].first, E[x].second);
			vec.clear();
			vec.pb(i);
		}
	}
	//for (int i=0; i<n-1; i++) cerr<<val[i]<<' ';cerr<<endl;
	for (int i=0; i<n-1; i++){
		if (val[i]==ans) cnt++;
		if (val[i]>ans){
			ans=val[i];
			cnt=1;
		}
	}
	cout<<ans*2<<' '<<cnt<<endl;
	for (int i=0; i<n-1; i++){
		if (val[i]==ans) cout<<i+1<<' ';
	}
	
	
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