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
const int MAXN = 100010, LOG=20;

struct DSU{
	int par[MAXN];
	int sz[MAXN];
	DSU(){ for (int i=1; i<MAXN; i++) par[i]=i, sz[i]=1;}
	int get(int x){
		if (par[x]==x) return x;
		return par[x]=get(par[x]);
	}
	void join(int x, int y){
		if (get(x)==get(y)) return ;
		sz[get(y)]+=sz[get(x)];
		par[get(x)]=get(y);
	}
	void reset(){ for (int i=1; i<MAXN; i++) par[i]=i, sz[i]=1;}
} dsu;

int n, m, k, u, v, x, y, t, a, b, ans;
int P[MAXN];

void init(){
	dsu.reset();
	for (int i=1; i<=n; i++) dsu.join(i, P[i]);
	t=0;
	for (int i=1; i<=n; i++) t+=dsu.par[i]==i;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>P[i];
	cin>>m;
	m=n-m;
	init();
	if (t==m) kill(0);
	//for (int i=1; i<=n; i++) cerr<<dsu.sz[i]<<' ';cerr<<endl;
	cout<<abs(t-m)<<'\n';
	if (t<m){
		while (t!=m){
			for (int i=1; i<=n; i++) if (dsu.sz[dsu.get(i)]>1){
					for (int j=i+1; j<=n; j++) if (dsu.get(i)==dsu.get(j)){
					cout<<i<<' '<<j<<' ';
					swap(P[i], P[j]);
					break ;
				}
				break ;
			}
			init();
		}
		return 0;
	}
	while (t!=m){
		for (int i=2; i<=n; i++) if (dsu.get(1)!=dsu.get(i)){
			cout<<"1 "<<i<<' ';
			swap(P[1], P[i]);
			break ;
		}
		init();
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