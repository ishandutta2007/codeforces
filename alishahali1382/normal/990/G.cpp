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

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000010LL;
const int mod = 1000000007;
const int MAXN = 200010;

struct DSU{
	int par[MAXN];
	int sz[MAXN];
	DSU(){
		for (int i=1; i<MAXN; i++) par[i]=i;
		for (int i=1; i<MAXN; i++) sz[i]=1;
	}
	bool root(int x){ return par[x]==x;}
	
	int get(int x){
		if (par[x]==x) return x;
		return par[x]=get(par[x]);
	}
	ll getsz(int x){
		return sz[get(x)];
	}
	
	bool join(int x, int y){
		if (get(x)==get(y)) return false;
		if (get(x)>get(y)) swap(x, y);
		sz[get(y)]+=sz[get(x)];
		par[get(x)]=get(y);
		return true;
	}
};

int n, m, u, v, x, y, t, a, b;
int A[MAXN];
int sieve[MAXN];
int M[MAXN];
int mark[MAXN];
ll cnt[MAXN];
ll ans[MAXN];
vector<int> G[MAXN], D[MAXN], vec[MAXN];

int mob(int x){
	int res=1;
	while(x>1){
		int tmp=sieve[x];
		x/=tmp;
		if (x%tmp==0) return 0;
		res=-res;
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i=1; i<MAXN; i++) sieve[i]=i;
	for (ll i=2; i*i<MAXN; i++){
		if (sieve[i]!=i) continue ;
		for (ll j=i*i; j<MAXN; j+=i) sieve[j]=i;
	}
	for (int i=1; i<MAXN; i++) for (int j=i; j<MAXN; j+=i) D[j].pb(i);
	for (int i=1; i<MAXN; i++) M[i]=mob(i);
	
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>A[i];
		for (int j:D[A[i]]) vec[j].pb(i);
	}
	for (int i=0; i<n-1; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	DSU dsu;
	for (int i=1; i<MAXN; i++){
		for (int v:vec[i]) mark[v]=i;
		for (int v:vec[i]){
			for (int u:G[v]) if (mark[u]==i) dsu.join(v, u);
		}
		for (int v:vec[i]) if (dsu.root(v)) cnt[i]+=dsu.getsz(v)*(dsu.getsz(v)+1)/2;
		for (int v:vec[i]) dsu.par[v]=v, dsu.sz[v]=1;
	}
	//for (int i=1; i<=32; i++) if (cnt[i]) cerr<<i<<" : "<<cnt[i]<<endl;
	for (int i=1; i<MAXN; i++){
		for (int j=i; j<MAXN; j+=i) ans[i]+=M[j/i]*cnt[j];
	}
	for (int i=1; i<MAXN; i++) if (ans[i]) cout<<i<<' '<<ans[i]<<endl;
	
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