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

ll powmod(ll a, ll b){
	if (b==0) return 1;
	if (b%2) return (a*powmod(a, b-1))%mod;
	return powmod(a*a%mod, b>>1);
}

ll mob(ll x){
	if (x==1) return 1;
	ll res=1;
	for (ll i=2; i*i<=x; i++){
		if (x%i==0){
			x/=i;
			res*=-1;
			if (x%i==0) return 0;
		}
	}
	if (x>1) res*=-1;
	
	return res;
}

ll s, cnt, ans, x, y, tmp;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>x>>y;
	if (y%x){
		cout<<0<<endl;
		return 0;
	}
	s=y/x;
	//debug(s);
	ll i=1;
	for (; i*i<s; i++){
		if (s%i) continue ;
		ans=(ans+powmod(2, s/i-1)*mob(i))%mod;
		ans=(ans+powmod(2, i-1)*mob(s/i))%mod;
		//cerr<<i<<' '<<s/i<<endl;
	}
	if (i*i==s) ans=(ans+powmod(2, i-1)*mob(i))%mod; 
	cout<<(ans+mod)%mod<<endl;
	
	//debug(mob(3));
	
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