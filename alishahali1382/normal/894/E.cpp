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
const int MAXN = 1000010, LOG=20;

ll f(ll w){
	ll dwn=0, up=w+1;
	while (up-dwn>1){
		ll mid=(dwn+up)/2;
		if (mid*(mid-1)/2>w) up=mid;
		else dwn=mid;
	}
	return dwn*w-(dwn+1)*dwn*(dwn-1)/6;
}

int n, m, k, u, v, x, y, t, a, b;
ll val[MAXN];
ll dp[MAXN];
int comp[MAXN];
bitset<MAXN> mark;
vector<pii> Gout[MAXN], Gin[MAXN];
vector<pii> G[MAXN];
vector<int> topol;

void dfs(int node){
	mark[node]=1;
	for (pii p:Gout[node]) if (!mark[p.first]) dfs(p.first);
	topol.pb(node);
}

void sfd(int node, int c){
	comp[node]=c;
	for (pii p:Gin[node]) if (!comp[p.first]) sfd(p.first, c);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	while (m--){
		cin>>u>>v>>x;
		Gout[u].pb({v, x});
		Gin[v].pb({u, x});
	}
	for (int i=1; i<=n; i++) if (!mark[i]) dfs(i);
	reverse(all(topol));
	for (int i:topol) if (!comp[i]) sfd(i, i);
	
	for (int i=1; i<=n; i++){
		for (pii p:Gout[i]){
			int j=p.first, w=p.second;
			if (comp[i]==comp[j]) val[comp[i]]+=f(w);
			else G[comp[i]].pb({comp[j], w});
		}
	}
	
	reverse(all(topol));
	for (int i:topol){
		for (pii p:G[i]) dp[i]=max(dp[i], dp[p.first]+p.second);
		dp[i]+=val[i];
	}
	
	int s;
	cin>>s;
	cout<<dp[comp[s]]<<'\n';
	
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