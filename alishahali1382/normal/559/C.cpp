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
const int MAXN = 300010;

ll powmod(ll a, ll b){
	if (b==0) return 1;
	if (b&1) return (a*powmod(a, b-1))%mod;
	return powmod(a*a%mod, b>>1);
}

ll n, h, w, ans, t;
ll F[MAXN], I[MAXN];
pii A[2010];
ll dp[2010];

ll C(ll n, ll r){
	if (r<0 || r>n) return 0;
	return (F[n]*I[r]%mod)*I[n-r]%mod;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	F[0]=I[0]=1;
	for (int i=1; i<MAXN; i++){
		F[i]=(F[i-1]*i)%mod;
		I[i]=(I[i-1]*powmod(i, mod-2))%mod;
	}
	cin>>h>>w>>n;
	for (int i=0; i<n; i++) cin>>A[i].first>>A[i].second;
	sort(A, A+n);
	A[n]={h, w};
	ll s=0;
	for (int i=0; i<=n; i++){
		dp[i]=C(A[i].first+A[i].second-2, A[i].first-1);
		//dp[i]=(dp[i]-s+mod)%mod;
		//for (int j=0; j<i; j++) s=(s+dp[i]*dp[j])%mod;
		//s=(s+dp[i])%mod;
		for (int j=0; j<i; j++){
			dp[i]=(dp[i]-dp[j]*C(A[i].first+A[i].second-A[j].first-A[j].second, A[i].first-A[j].first))%mod;
		}
		dp[i]=(dp[i]+mod)%mod;
	}
	//for (int i=0; i<=n; i++) cerr<<dp[i]<<' ';cerr<<endl;
	
	cout<<dp[n]<<endl;
	
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