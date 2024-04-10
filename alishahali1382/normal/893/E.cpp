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
const int MAXN = 1000010;

ll n, q, x, y, ans;
ll dp[21][MAXN];
ll tav[MAXN];
ll F[MAXN];
ll I[MAXN];

ll powmod(ll a, ll b){
	if (!b) return 1;
	if (b&1) return (a*powmod(a, b-1))%mod;
	return powmod(a*a%mod, b>>1);
}

ll C(ll n, ll r){
	return (F[n]*I[r]%mod)*I[n-r]%mod;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	tav[0]=F[0]=I[0]=1;
	for (int i=1; i<MAXN; i++) tav[i]=(2*tav[i-1])%mod;
	for (int i=1; i<MAXN; i++) F[i]=(i*F[i-1])%mod;
	for (int i=1; i<MAXN; i++) I[i]=(I[i-1]*powmod(i, mod-2))%mod;
	dp[0][1]=1;
	for (int i=0; i<20; i++){
		for (int j=1; j<=1000000; j++){
			if (!dp[i][j]) continue ;
			for (int k=2*j; k<=1000000; k+=j) dp[i+1][k]=(dp[i+1][k]+dp[i][j])%mod;
		}
	}
	cin>>q;
	while (q--){
		cin>>x>>y;
		ans=0;
		for (int i=0; i<=min(20ll, y); i++) ans=(ans+dp[i][x]*C(y, y-i))%mod;
		ans=(ans*tav[y-1])%mod;
		cout<<ans<<'\n';
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