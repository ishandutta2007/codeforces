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
const int MAXN = 100010;

int n, m, k, x, y, w, t=1, ans, a, b, xt, yt, xm, ym;
bool A[2][2*MAXN];
int dist[2][2*MAXN];
queue<pii> q;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	char ch;
	for (int j=0; j<2; j++)for (int i=0; i<n; i++){
		cin>>ch;
		A[j][i]=(ch=='X');
	}
	memset(dist, 63, sizeof(dist));
	dist[0][0]=0;
	q.push({0, 0});
	while (!q.empty()){
		int x=q.front().first, y=q.front().second;
		q.pop();
		//cerr<<x<<' '<<y<<endl;
		if (y<dist[x][y] || A[x][y]) continue ;
		if (y>=n-1){
			cout<<"YES"<<endl;
			return 0;
		}
		if (dist[x][y]+1<dist[x][y+1]){
			dist[x][y+1]=dist[x][y]+1;
			q.push({x, y+1});
		}
		if (dist[x][y]+1<dist[x][y-1] && y){
			dist[x][y-1]=dist[x][y]+1;
			q.push({x, y-1});
		}
		if (dist[x][y]+1<dist[1-x][y+k]){
			dist[1-x][y+k]=dist[x][y]+1;
			q.push({1-x, y+k});
		}
	}
	cout<<"NO"<<endl;
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