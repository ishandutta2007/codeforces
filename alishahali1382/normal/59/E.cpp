#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<short, short> pii;
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
const int MAXN = 3010;

int n, m, k, u, v, x, y, t, a, b, ans;
int dist[MAXN][MAXN];
short par[MAXN][MAXN];
piii bad[100010];
vector<short> G[MAXN];
queue<int> q;
stack<int> out;

void print(int a, int b){
	while (a!=b){
		out.push(b);
		int x=par[a][b];
		b=a;
		a=x;
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	memset(dist, 63, sizeof(dist));
	cin>>n>>m>>k;
	while (m--){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	for (int i=0; i<k; i++){
		cin>>a>>b>>x;
		bad[i]={{a, b}, x};
	}
	sort(bad, bad+k);
	dist[1][1]=0;
	q.push(MAXN+1);
	while (!q.empty()){
		int x=q.front();
		int a=x/MAXN, b=x%MAXN;
		q.pop();
		if (b==n){
			cout<<dist[a][b]<<'\n';
			cout<<"1 ";
			print(a, b);
			while (!out.empty()){
				cout<<out.top()<<' ';
				out.pop();
			}
			return 0;
		}
		for (int x:G[b]){
			piii p={{a, b}, x};
			if ((*lower_bound(bad, bad+k, p))==p) continue ;
			if (dist[a][b]+1<dist[b][x]){
				dist[b][x]=dist[a][b]+1;
				q.push(b*MAXN+x);
				par[b][x]=a;
			}
		}
	}
	cout<<"-1\n";
	
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