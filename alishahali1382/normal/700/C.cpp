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
const int inf=2000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 100010, LOG=20;

struct edge{
	int u, v, w;
} E[MAXN];

int n, m, k, u, v, x, y, t, s, ans=inf, bad;
int parid[MAXN];
int backe[MAXN];
int h[MAXN];
int parent[MAXN];
vector<pii> G[MAXN];
vector<int> out, path;
bitset<MAXN> mark;

bool findpath(int node){
	mark[node]=1;
	if (node==t) return 1;
	for (pii p:G[node]) if (!mark[p.first]){
		path.pb(p.second);
		if (findpath(p.first)) return 1;
		path.pop_back();
	}
	return 0;
}

void dfs(int node, int par){
	mark[node]=1;
	backe[node]=h[node]=h[par]+1;
	parent[node]=par;
	//if (node==t) return ;
	for (pii p:G[node]) if (p.second!=parid[node] && p.second!=bad){
		if (mark[p.first]) backe[node]=min(backe[node], h[p.first]);
		else{
			parid[p.first]=p.second;
			dfs(p.first, node);
			backe[node]=min(backe[node], backe[p.first]);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>s>>t;
	for (int i=1; i<=m; i++){
		cin>>E[i].u>>E[i].v>>E[i].w;
		G[E[i].u].pb({E[i].v, i});
		G[E[i].v].pb({E[i].u, i});
	}
	if (!findpath(s)) return puts("0\n0");
	for (int id:path){
		bad=id;
		if (E[id].w>=ans) continue ;
		//debug(bad)
		mark=0;
		dfs(s, 0);
		
		if (!mark[t]){
			ans=E[id].w;
			out={id};
			continue ;
		}
		for (int cur=t; cur!=s; cur=parent[cur]) if (backe[cur]>=h[cur]){
			if (E[bad].w+E[parid[cur]].w<ans){
				ans=E[bad].w+E[parid[cur]].w;
				out={bad, parid[cur]};
			}
		}
		
	}
	if (ans>=inf) kill(-1)
	cout<<ans<<'\n'<<out.size()<<'\n';
	for (int i:out) cout<<i<<' ';
	
	
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