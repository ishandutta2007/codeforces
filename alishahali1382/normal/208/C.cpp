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
const int MAXN = 110;

ll n, m, k, u, v, x, y, t, a, b, ans;
int dist[MAXN];
ll cnt1[MAXN];
ll cnt2[MAXN];
ll dp[MAXN];
queue<int> q;
vector<int> G[MAXN];
vector<int> Gin[MAXN], Gout[MAXN];

ll f1(int node){
	if (cnt1[node]!=-1) return cnt1[node];
	cnt1[node]=0;
	for (int i:Gout[node]) cnt1[node]+=f1(i);
	return cnt1[node];
}
ll f2(int node){
	if (cnt2[node]!=-1) return cnt2[node];
	cnt2[node]=0;
	for (int i:Gin[node]) cnt2[node]+=f2(i);
	return cnt2[node];
}




int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	while (m--){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	memset(dist, 31, sizeof(dist));
	dist[1]=0;
	q.push(1);
	while (!q.empty()){
		int v=q.front();
		q.pop();
		for (int i:G[v]){
			if (dist[v]+1<dist[i]){
				dist[i]=dist[v]+1;
				q.push(i);
			}
		}
	}
	for (int i=1; i<=n; i++){
		for (int j:G[i]){
			if (dist[i]+1!=dist[j]) continue ;
			Gout[i].pb(j);
			Gin[j].pb(i);
		}
	}
	memset(cnt1, -1, sizeof(cnt1));
	memset(cnt2, -1, sizeof(cnt2));
	cnt1[n]=1;
	cnt2[1]=1;
	f1(1);
	f2(n);
	
	//for (int i=1; i<=n; i++) cerr<<cnt1[i]<<' ';cerr<<endl;
	//for (int i=1; i<=n; i++) cerr<<cnt2[i]<<' ';cerr<<endl;
	
	for (int i=2; i<n; i++) ans=max(ans, 2*cnt1[i]*cnt2[i]);
	ans=max(ans, cnt1[1]);
	
	ld out=1.*ans/cnt1[1];
	cout<<setprecision(10)<<fixed<<out<<'\n';
	
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