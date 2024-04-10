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

char A[MAXN][MAXN];
bool mask[MAXN][MAXN][4];

bool right(int x, int y, int t){
	return mask[x][y][(t+1)%4] && mask[x][y+1][(t+3)%4];
}
bool left(int x, int y, int t){
	return mask[x][y][(t+3)%4] && mask[x][y-1][(t+1)%4];
}
bool up(int x, int y, int t){
	return mask[x][y][t%4] && mask[x-1][y][(t+2)%4];
}
bool down(int x, int y, int t){
	return mask[x][y][(t+2)%4] && mask[x+1][y][t%4];
}

int n, m, k, x, y, w, t=1, ans, v, u, q, xt, yt, xm, ym;
int dp[MAXN][MAXN][4];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++){
		cin>>A[i][j];
		if (A[i][j]=='+') mask[i][j][0]=mask[i][j][1]=mask[i][j][2]=mask[i][j][3]=true;
		if (A[i][j]=='-') mask[i][j][1]=mask[i][j][3]=true;
		if (A[i][j]=='|') mask[i][j][0]=mask[i][j][2]=true;
		if (A[i][j]=='^') mask[i][j][0]=true;
		if (A[i][j]=='>') mask[i][j][1]=true;
		if (A[i][j]=='v') mask[i][j][2]=true;
		if (A[i][j]=='<') mask[i][j][3]=true;
		if (A[i][j]=='U') mask[i][j][1]=mask[i][j][2]=mask[i][j][3]=true;
		if (A[i][j]=='R') mask[i][j][0]=mask[i][j][2]=mask[i][j][3]=true;
		if (A[i][j]=='D') mask[i][j][0]=mask[i][j][1]=mask[i][j][3]=true;
		if (A[i][j]=='L') mask[i][j][0]=mask[i][j][1]=mask[i][j][2]=true;
	}
	
	cin>>xt>>yt>>xm>>ym;
	memset(dp, 63, sizeof(dp));
	
	queue<piii> q;
	dp[xt][yt][0]=0;
	q.push({{xt, yt}, 0});
	
	while (!q.empty()){
		piii p=q.front();
		q.pop();
		int x=p.first.first, y=p.first.second, t=p.second;
		if (x>n || y>m || x<1 || y<1 || A[x][y]=='*') continue ;
		//cerr<<x<<' '<<y<<' '<<t<<endl;
		//debug(dp[x][y][t]);
		/*if (x==xm && y==ym){
			cout<<dp[x][y][t]<<endl;
			return 0;
		}*/
		if (dp[x][y][t]+1<dp[x][y][(t+1)%4]){
			dp[x][y][(t+1)%4]=dp[x][y][t]+1;
			q.push({{x, y}, (t+1)%4});
		}
		if (dp[x][y][t]+1<dp[x+1][y][t] && down(x, y, 4-t)){
			dp[x+1][y][t]=dp[x][y][t]+1;
			q.push({{x+1, y}, t});
		}
		if (dp[x][y][t]+1<dp[x][y+1][t] && right(x, y, 4-t)){
			dp[x][y+1][t]=dp[x][y][t]+1;
			q.push({{x, y+1}, t});
		}
		if (dp[x][y][t]+1<dp[x-1][y][t] && up(x, y, 4-t)){
			dp[x-1][y][t]=dp[x][y][t]+1;
			q.push({{x-1, y}, t});
		}
		if (dp[x][y][t]+1<dp[x][y-1][t] && left(x, y, 4-t)){
			dp[x][y-1][t]=dp[x][y][t]+1;
			q.push({{x, y-1}, t});
		}
	}
	//debug(up(3, 3, 0));
	//debug(mask[3][3][0]);
	//debug(mask[2][3][2])
	//debug(A[3][2]);
	//debug(A[1][1]);
	
	int ans=inf;
	for (int i=0; i<4; i++) ans=min(ans, dp[xm][ym][i]);
	if (ans<inf) cout<<ans<<endl;
	else cout<<-1<<endl;
	
	return 0;
}
/*
3 3
->v
*+|
+*^
3 3
1 1
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