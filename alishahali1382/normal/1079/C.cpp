#include <bits/stdc++.h>
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
const int MAXN = 100010;

int n, m, ans, k, a, b, c, cnt;
int A[MAXN];
bool dp[MAXN][5];
int upd[MAXN][5];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>A[1];
	dp[1][0]=dp[1][1]=dp[1][2]=dp[1][3]=dp[1][4]=1;
	for (int i=2; i<=n; i++){
		cin>>A[i];
		if (A[i]>=A[i-1]){
			for (int x=0; x<5; x++){
				if (!dp[i-1][x]) continue ;
				for (int y=x+1; y<5; y++){
					dp[i][y]=1;
					upd[i][y]=x;
				}
				break ;
			}
		}
		if (A[i]<=A[i-1]){
			for (int x=4; x; x--){
				if (!dp[i-1][x]) continue ;
				for (int y=0; y<x; y++){
					dp[i][y]=1;
					upd[i][y]=x;
				}
				break ;
			}
		}
	}
	/*
	cerr<<endl;
	for (int j=0; j<5; j++){
		for (int i=1; i<=n; i++) cerr<<dp[i][j]<<' ';	
		cerr<<endl;
	}
	cerr<<endl;
	*/
	int last=-1;
	for (int i=0; i<5; i++) if (dp[n][i]) last=i;
	if (last==-1){
		cout<<-1<<endl;
		return 0;
	}
	stack<int> out;
	out.push(last+1);
	for (int i=n-1; i; i--){
		last=upd[i+1][last];
		out.push(last+1);
	}
	while (!out.empty()){
		cout<<out.top()<<' ';
		out.pop();
	}
	cout<<endl;
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