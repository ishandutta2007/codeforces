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

ll n, q, x, k, y, ans, s;
ll tav[MAXN];
ll F[MAXN];
ll I[MAXN];
ll dp[MAXN];
ll B[MAXN];
int A[MAXN];
int ps[MAXN];
string str;

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
	for (int i=1; i<MAXN; i++) tav[i]=(10*tav[i-1])%mod;
	for (int i=1; i<MAXN; i++) F[i]=(i*F[i-1])%mod;
	for (int i=1; i<MAXN; i++) I[i]=(I[i-1]*powmod(i, mod-2))%mod;
	cin>>n>>k;
	cin>>str;
	for (int i=1; i<=n; i++) A[i]=str[i-1]-'0';
	for (int i=1; i<=n; i++) ps[i]=ps[i-1]+A[i];
	
	for (int i=1; i<=n; i++){
		B[i]=(C(n-i-1, k-1)*tav[i-1])%mod;
	}
	//for (int i=0; i<=n; i++) cerr<<B[i]<<' ';cerr<<endl;
	for (int i=1; i<n; i++){
		ans=(ans+ps[n-i]*B[i])%mod;
	}
	//debug(ans);
	for (int i=0; i<n; i++){
		ans=(ans+A[i+1]*tav[n-i-1]*C(i, k))%mod;
	}
	/*
	6 3
	967181
	*/
	
	
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