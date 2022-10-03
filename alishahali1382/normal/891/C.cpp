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
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 500010;

struct edge{
	int w, u, v;
} E[MAXN];

bool cmp(int i, int j){ return E[i].w<E[j].w;}

struct DSU{
	int par[MAXN];
	DSU(){
		for (int i=1; i<MAXN; i++) par[i]=i;
	}
	int get(int x){
		if (par[x]==x) return x;
		return par[x]=get(par[x]);
	}
	bool check(edge e){
		return get(e.u)==get(e.v);
	}
	edge make(edge e){
		e.u=get(e.u);
		e.v=get(e.v);
		return e;
	}
	int join(edge e){
		if (check(e)) return 0;
		par[get(e.u)]=get(e.v);
		return 1;
	}
} dsu;

int n, m, k, u, v, x, y, t, a, b, ans, q;
int ind[MAXN];
bool bad[MAXN];
vector<int> vec;

int query(){
	for (int i:vec) dsu.par[i]=i;
	vec.clear();
	cin>>k;
	for (int i=0; i<k; i++) cin>>ind[i];
	for (int i=0; i<k; i++){
		x=--ind[i];
		if (bad[x] || !dsu.join(E[x])) kill("NO");
		vec.pb(E[x].u);
		vec.pb(E[x].v);
	}
	kill("YES");
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=0; i<m; i++) cin>>E[i].u>>E[i].v>>E[i].w, ind[i]=i;
	sort(ind, ind+m, cmp);
	for (int i=0, j=0; i<m; i=j){
		while (j<m && E[ind[j++]].w==E[ind[j]].w) ;
		for (int x=i; x<j; x++) if (dsu.check(E[ind[x]])) bad[ind[x]]=1;
		for (int x=i; x<j; x++) E[ind[x]]=dsu.make(E[ind[x]]);
		for (int x=i; x<j; x++) dsu.join(E[ind[x]]);
	}
	//for (int i=0; i<m; i++) cerr<<bad[i]<<' ';cerr<<endl;
	for (int i=1; i<=n; i++) dsu.par[i]=i;
	cin>>q;
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