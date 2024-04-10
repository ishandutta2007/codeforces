#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
#define pb push_back

const ld eps=1e-7;
const int inf=1000000010;
const int mod = 1000000007;
const int MAXN = 100010;

ll n, m, x, ans;
int A[10][MAXN];
int B[10][MAXN];
int dp[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++){
		cin>>x;
		A[0][x]=i;
	}
	for (int i=1; i<m; i++){
		for (int j=1; j<=n; j++){
			cin>>x;
			A[i][j]=A[0][x];
		}
		for (int j=1; j<=n; j++) B[i][A[i][j]]=j;
		
	}
	for (int i=1; i<=n; i++) A[0][i]=i;
	/*
	for (int i=0; i<m; i++){
		for (int j=1; j<=n; j++) cerr<<A[i][j]<<' ';cerr<<endl; 
	}*/
	dp[n]=1;
	for (int i=n-1; i; i--){
		dp[i]=n-i+1;
		for (int j=1; j<m; j++){
			if (B[j][i]+1!=B[j][i+1]) dp[i]=1;
			else dp[i]=min(dp[i], dp[i+1]+1);
		}
	}/*
	for (int i=1; i<m; i++){
		for (int j=1; j<=n; j++) cerr<<B[i][j]
	}*/
	//for (int i=1; i<=n; i++) cerr<<dp[i]<<' ';cerr<<endl;
	for (int i=1; i<=n; i++) ans+=dp[i];
	cout<<ans<<endl;
	
	
	return 0;
}
/*
                                                                                                            __                    .----.                    
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