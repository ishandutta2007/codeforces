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
const int MAXN = 1010;

vector<pii> adj={{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int n, m, p, u, v, x, y, t, a, b;
int S[10];
int A[MAXN][MAXN];
int dis[MAXN][MAXN];
queue<pii> q;
char ch;
int ans[10];

void bfs(int rx, int ry){
	queue<pii> Q;
	vector<pii> vec;
	Q.push({rx, ry});
	dis[rx][ry]=0;
	while (!Q.empty()){
		int x=Q.front().first, y=Q.front().second;
		Q.pop();
		if (dis[x][y]==S[A[rx][ry]]) break ;
		//cerr<<x<<' '<<y<<endl;
		for (pii p:adj){
			int nx=x+p.first, ny=y+p.second;
			//debug(nx)
			//debug(ny)
			//debug(A[nx][ny])
			if (!nx || !ny || nx>n || ny>m || A[nx][ny]) continue ;
			//debug("fuck this shit")
			if (dis[x][y]+1<dis[nx][ny]){
				//debug("hello")
				A[nx][ny]=A[rx][ry];
				dis[nx][ny]=dis[x][y]+1;
				Q.push({nx, ny});
				q.push({nx, ny});
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i=0; i<MAXN; i++) for (int j=0; j<MAXN; j++) dis[i][j]=inf;
	cin>>n>>m>>p;
	for (int i=1; i<=p; i++) cin>>S[i];
	vector<pii> vec[10];
	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++){
		cin>>ch;
		if (ch=='#') A[i][j]=-1;
		else if (ch!='.'){
			A[i][j]=ch-'0';
			vec[A[i][j]].pb({i, j});
			dis[i][j]=0;
		}
	}
	for (int i=1; i<=p; i++) for (pii p:vec[i]) q.push(p);
	while (!q.empty()){
		int x=q.front().first, y=q.front().second;
		q.pop();
		//cerr<<x<<' '<<y<<endl;
		bfs(x, y);
	}/*
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) cerr<<A[i][j]<<' ';cerr<<endl;
	}*/
	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++)  if (A[i][j]>0) ans[A[i][j]]++;
	for (int i=1; i<=p; i++) cout<<ans[i]<<' ';
	
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