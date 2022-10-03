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
const ll inf=1e18+100;
const int mod = 1000000007;
const int MAXN = 100010;

ll n, ans, x, t;
ll dp[50][50];
ll tav[20];
bool upd[50][50];
char ch;

ll f(int x){
	if (x<0) return 0;
	return tav[x];
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	tav[0]=1;
	for (int i=1; i<20; i++) tav[i]=tav[i-1]*10;
	cin>>n;
	for (int i=1; i<=2*n; i++){
		cin>>ch;
		x=ch-'0';
		if (i<=n) dp[i][i]=dp[i][0]=dp[i-1][0]+x*f(n-i);
		upd[i][i]=true;
		
		for (int j=1; j<=n && j<i; j++){
			dp[i][j]=dp[i-1][j]+f(n-i+j)*x;
			//if (i==6 && j==1) cerr<<dp[i][j]<<endl;
			ll tmp=dp[i-1][j-1]+f(n-j)*x;
			
			if (tmp>=dp[i][j]){
				dp[i][j]=tmp;
				upd[i][j]=true;
			}
		}
		for (int j=i+1; j<=n*2; j++) dp[i][j]=-inf;
	}
	for (int i=1; i<=2*n; i++){
		for (int j=0; j<=n; j++) cerr<<dp[i][j]<<' ';
		cerr<<endl;
	}
	/*
	for (int i=1; i<=2*n; i++){
		for (int j=0; j<=n; j++) cerr<<upd[i][j]<<' ';
		cerr<<endl;
	}*/
	
	//cerr<<dp[2*n][n]<<endl;
	string out="";
	for (int i=2*n, j=n; i; i--){
		if (upd[i][j]){
			out="M"+out;
			j--;
		}
		else out="H"+out;
	}
	cout<<out<<endl;
	
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