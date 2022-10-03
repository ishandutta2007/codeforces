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
const ll infll=1e18+100;
const int inf=1e9+100;
const int mod = 1000000007;
const int MAXN = 1010;

ll n, q, x, y, tmp, k;
int dp[50][MAXN][MAXN];  // dp[i][j][k]:  x1 + x2 + x3 + ... + xi = j   x1<=k x2<=k x3<=k ... xi<=k
int ans[50][MAXN];
ll F[MAXN*10];
ll I[MAXN*10];

ll powmod(ll a, ll b){
	if (!b) return 1;
	if (b&1) return (a*powmod(a, b-1))%mod;
	return powmod(a*a%mod, b>>1);
}

ll C(ll n, ll r){
	if (r>n || r<0) return 0;
	return (F[n]*I[r]%mod)*I[n-r]%mod;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	F[0]=I[0]=1;
	for (int i=1; i<MAXN*10; i++) F[i]=(i*F[i-1])%mod;
	for (int i=1; i<MAXN*10; i++) I[i]=(I[i-1]*powmod(i, mod-2))%mod;
	for (int j=0; j<=1000; j++) for (int k=j; k<=1000; k++) dp[1][j][k]=1;
	for (int i=2; i<50; i++){
		for (int j=1; j<=1000; j++){
			for (int k=1; k<=j; k++) dp[i][j][k]=(dp[i][j][k-1]+dp[i-1][j-k][k-1])%mod;
			for (int k=j+1; k<=1000; k++) dp[i][j][k]=dp[i][j][j];
		}
	}
	for (int i=1; i<50; i++){
		for (int j=1; j<=1000; j++){
			for (int k=0; k<=j; k++) ans[i][j]=((ll)ans[i][j]+dp[i][k][1000]*C(j-k, i))%mod;
		}
	}
	/*
	debug(ans[1][1]);
	debug(ans[2][2]);
	debug(dp[1][0][1000]);
	debug(dp[1][1][1000]);
	*/
	cin>>q;
	while (q--){
		cin>>n>>k;
		if (k>=50){
			cout<<0<<'\n';
			continue ;
		}
		tmp=ans[k][n]*F[k]%mod;
		cout<<tmp<<'\n';
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