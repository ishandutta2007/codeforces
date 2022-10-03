#include <bits/stdc++.h>
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
const int mod = 1000000007;
const int MAXN = 1010;

int n, m, t, x, y, xx, yy, ans, v, u, q, a, b, c, cnt;
char A[MAXN][MAXN];
int dist[MAXN][MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			cin>>A[i][j];
			if (A[i][j]=='S'){
				xx=i;
				yy=j;
			}
			if (A[i][j]=='E'){
				x=i;
				y=j;
			}
		}
	}
	queue<pii> q;
	q.push({x, y});
	memset(dist, 63, sizeof(dist));
	dist[x][y]=0;
	while (!q.empty()){
		int x=q.front().first, y=q.front().second;
		q.pop();
		if (dist[x][y]>dist[xx][yy]) break ;
		if (x<1 || y<1 || x>n || y>m || A[x][y]=='T') continue ;
		if (dist[x][y]+1<dist[x+1][y]){
			dist[x+1][y]=dist[x][y]+1;
			q.push({x+1, y});
		}
		if (dist[x][y]+1<dist[x][y+1]){
			dist[x][y+1]=dist[x][y]+1;
			q.push({x, y+1});
		}
		if (dist[x][y]+1<dist[x-1][y]){
			dist[x-1][y]=dist[x][y]+1;
			q.push({x-1, y});
		}
		if (dist[x][y]+1<dist[x][y-1]){
			dist[x][y-1]=dist[x][y]+1;
			q.push({x, y-1});
		}
	}
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			if (A[i][j]=='S' || A[i][j]=='E' || A[i][j]=='T') continue ;
			if (dist[i][j]<=dist[xx][yy]) ans+=A[i][j]-'0';
			//cerr<<i<<' '<<j<<' '<<A[i][j]<<' '<<dist[i][j]<<endl;
		}
	}
	cout<<ans<<endl;
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