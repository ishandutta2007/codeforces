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
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 100010, LOG=20;

int n, m, k, u, v, x, y, t, odd=-1;
int L[MAXN], R[MAXN];
bitset<MAXN> ans;
bitset<MAXN*2> mark;
vector<pii> G[MAXN*2];
vector<int> compress;

void tour(int node){
	while (!G[node].empty()){
		pii p=G[node].back();
		G[node].pop_back();
		int v=p.first, i=p.second;
		if (mark[i]) continue ;
		mark[i]=1;
		tour(v);
		ans[i]=(node>v);
	}
}

void addedge(int u, int v){
	//cerr<<"edge : "<<u<<' '<<v<<' '<<t<<endl;
	G[u].pb({v, t});
	G[v].pb({u, t++});
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=0; i<n; i++){
		cin>>L[i]>>R[i];
		R[i]++;
		compress.pb(L[i]);
		compress.pb(R[i]);
	}
	sort(all(compress));
	compress.resize(unique(all(compress))-compress.begin());
	for (int i=0; i<n; i++){
		L[i]=lower_bound(all(compress), L[i])-compress.begin();
		R[i]=lower_bound(all(compress), R[i])-compress.begin();
		addedge(L[i], R[i]);
	}
	for (int i=0; i<2*MAXN; i++) if (G[i].size()&1){
		if (odd==-1) odd=i;
		else{
			addedge(odd, i);
			odd=-1;
		}
	}
	for (int i=0; i<2*MAXN; i++) tour(i);
	
	for (int i=0; i<n; i++) cout<<ans[i]<<' ';
	
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