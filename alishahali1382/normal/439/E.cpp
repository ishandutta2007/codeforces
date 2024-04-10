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

ll powmod(ll a, ll b){
	if (b==0) return 1;
	if (b%2) return a*powmod(a, b-1)%mod;
	return powmod(a*a%mod, b>>1);
}

ll n, m, k, x, y, w, q, ans, a, b, xt, yt, xm, ym;
ll F[MAXN];
ll I[MAXN];
int M[MAXN];
int sieve[MAXN];
vector<int> D[MAXN];

int mu(int x){
	int res=1;
	for (; x>1; x/=sieve[x]){
		if ((x/sieve[x])%sieve[x]==0) return 0;
		res=-res;
	}
	return res;
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
	for (int i=1; i<=100000; i++){
		F[i]=(F[i-1]*i)%mod;
		I[i]=(I[i-1]*powmod(i, mod-2))%mod;
		sieve[i]=i;
	}
	for (int i=2; i*i<=100000; i++){
		if (sieve[i]!=i) continue ;
		for (int j=i*i; j<=100000; j+=i) sieve[j]=i;
	}
	for (int i=1; i<=100000; i++){
		for (int j=i; j<=100000; j+=i) D[j].pb(i);
	}
	for (int i=1; i<=100000; i++) M[i]=mu(i);
	
	cin>>q;
	while (q--){
		cin>>n>>m;
		ans=0;
		for (int d:D[n]) ans=(ans+M[d]*C(n/d-1, m-1))%mod;
		cout<<(mod+ans)%mod<<'\n';
	}
	
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