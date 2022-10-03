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
const int MAXN = 200010;

vector<pii> G[MAXN];
struct edge{
	int u, v;
} E[MAXN];

int n, m, k, u, v, x, y, t, a, b;
bool ok[MAXN]; // if CNF[i] ok?
bool ans[MAXN];
int H[MAXN];
int mark[MAXN];
vector<int> CNF[MAXN];
vector<pii> A[MAXN];
queue<int> q;

bool good(int i){ // is A[i] good?
	if (!A[i].size()) return 0;
	if (A[i].size()==1) return 1;
	return A[i][0].second==A[i][1].second || ok[A[i][0].first] || ok[A[i][1].first];
}

int dfs0(int node, int id){
	mark[node]=1;
	for (pii p:G[node]){
		int v=p.first, i=p.second;
		if (i==id) continue ;
		if (mark[v]) return v;
		int x=dfs0(v, i);
		if (x) return x;
	}
	return 0;
}

void dfs(int node, int id, int h=0){
	//cerr<<"dfs "<<node<<' '<<id<<endl;
	//cerr<<E[id].u<<' '<<E[id].v<<endl;
	H[node]=h;
	mark[node]=2;
	if (E[id].v==node) ans[id]=0;
	else ans[id]=1;
	for (pii p:G[node]){
		int v=p.first, i=p.second;
		if (i==id) continue ;
		if (mark[v]==2 && H[v]<h) continue ;
		if (mark[v]==2){
			//cerr<<"backedge "<<node<<' '<<v<<' '<<i<<endl;
			if (E[i].v==v) ans[i]=1;
			else ans[i]=0;
			continue ;
		}
		dfs(v, i, h+1);
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++){
		cin>>k;
		while (k--){
			cin>>x;
			CNF[i].pb(x);
			if (x>0) A[x].pb({i, 1});
			else A[-x].pb({i, 0});
		}
	}
	for (int i=1; i<=m; i++) if (A[i].size()==2 && A[i][1].second) swap(A[i][0], A[i][1]);
	for (int i=1; i<=m; i++) if (good(i)) q.push(i);
	while (!q.empty()){
		int i=q.front();
		q.pop();
		if (!good(i)) continue ;
		//debug(i)
		if (A[i].size()==1) ans[i]=A[i][0].second;
		else{
			if (A[i][0].second==A[i][1].second) ans[i]=A[i][0].second;
			else if (ok[A[i][0].first]) ans[i]=A[i][1].second;
			else if (ok[A[i][1].first]) ans[i]=A[i][0].second;
			else ans[i]=A[i][1].second;
		}
		for (pii p:A[i]){
			ok[p.first]=1;
			for (int j:CNF[p.first]) if (good(abs(j))) q.push(abs(j));
		}
		A[i].clear();
	}
	for (int i=1; i<=m; i++) if (A[i].size()){
		int u=A[i][0].first, v=A[i][1].first;
		//cerr<<"edge : "<<u<<' '<<v<<endl;
		E[i]={u, v};
		G[u].pb({v, i});
		G[v].pb({u, i});
	}/*
	for (int i=1; i<=n; i++){
		cerr<<i<<" :\n";
		for (pii p:G[i]) debugp(p);
	}*/
	for (int i=1; i<=n; i++) if (!ok[i] && mark[i]!=2){
		int x=dfs0(i, 0);
		if (!x) kill("NO")
		debug(x)
		dfs(x, 0);
	}
	
	
	
	cout<<"YES\n";
	for (int i=1; i<=m; i++) cout<<ans[i];
	
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