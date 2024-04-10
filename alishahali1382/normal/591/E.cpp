#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<x<<endl;
#define debugp(x) cerr<<#x<<"= {"<<x.first<<", "<<x.second<<"}"<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back

const ld eps=1e-7;
const int inf=1000000010;
const int mod = 1000000007;
const int MAXN = 1010;

int n, m, u, v, x, y, t, a, b, rx, ry, ans;
int A[MAXN][MAXN];
int dist[MAXN][MAXN][3];
deque<pii> q[3];
char ch;
int X[]={0, 0, 1, -1};
int Y[]={1, -1, 0, 0};

bool check(int x, int y){
	return 0<x && x<=n && 0<y && y<=m && A[x][y];
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;/*
	if (n==1000){
		cout<<896<<endl;
		return 0;
	}*/
	int T=1;
	memset(dist, 63, sizeof(dist));
	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++){
		cin>>ch;
		if (ch=='#') A[i][j]=0;
		if (ch=='.') A[i][j]=4;
		if (ch=='1'){
			A[i][j]=1;
			q[0].pb({i, j});
			dist[i][j][0]=0;/*
			for (int k=0; k<4; k++){
				if (!check(i+X[k], j+Y[k])) continue ;
				dist[i+X[k]][j+Y[k]][0]=T;
				q[0].push({i+X[k], j+Y[k]});
			}*/
		}
		if (ch=='2'){
			A[i][j]=2;
			q[1].pb({i, j});
			dist[i][j][1]=0;/*
			for (int k=0; k<4; k++){
				if (!check(i+X[k], j+Y[k])) continue ;
				dist[i+X[k]][j+Y[k]][1]=T;
				q[1].push({i+X[k], j+Y[k]});
			}*/
		}
		if (ch=='3'){
			A[i][j]=3;
			q[2].pb({i, j});
			dist[i][j][2]=0;/*
			for (int k=0; k<4; k++){
				if (!check(i+X[k], j+Y[k])) continue ;
				dist[i+X[k]][j+Y[k]][2]=T;
				q[2].push({i+X[k], j+Y[k]});
			}*/
		}
	}
	for (int i=0; i<3; i++){
		while (!q[i].empty()){
			pii p=q[i].front();
			q[i].pop_front();
			int x=p.first, y=p.second;
			/*
			if (!i){
				cerr<<x<<' '<<y<<' '<<dist[x][y][i]<<endl;
			}*/
			for (int j=0; j<4; j++){
				int xx=x+X[j], yy=y+Y[j];
				if (!check(xx, yy)) continue ;
				if (A[xx][yy]==4 && dist[x][y][i]+1<dist[xx][yy][i]){
					dist[xx][yy][i]=dist[x][y][i]+1;
					q[i].pb({xx, yy});
				}
				if (A[xx][yy]!=4 && dist[x][y][i]<dist[xx][yy][i]){
					dist[xx][yy][i]=dist[x][y][i];
					q[i].push_front({xx, yy});
				}
			}
		}
	}/*
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			cerr<<dist[i][j][0]<<' ';
		}
		cerr<<endl;
	}*/
	
	ll ans=inf;
	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++){
		if (!A[i][j]) continue ;
		if (A[i][j]==4) ans=min(ans, (ll) dist[i][j][0]+dist[i][j][1]+dist[i][j][2]-2);
		if (A[i][j]==1) ans=min(ans, (ll) dist[i][j][1]+dist[i][j][2]);
		if (A[i][j]==2) ans=min(ans, (ll) dist[i][j][0]+dist[i][j][2]);
		if (A[i][j]==3) ans=min(ans, (ll) dist[i][j][0]+dist[i][j][1]);
	}	
	if (ans>=inf) ans=-1;
	cout<<ans<<endl;
	
	return 0;
}
/*
10 10
..#.....#.
.####...#.
..#.......
..111.....
#..#.....#
.#...2....
.....2....
.....222..
..........
#.3....#..
*/
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