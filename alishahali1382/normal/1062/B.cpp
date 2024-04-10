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

ll n, a, b, x, y, ans, cnt;

bool rad(ll x){
	ll tmp=sqrt(x);
	return tmp*tmp==x || (tmp+1)*(tmp+1)==x;
}

ll f(ll x){
	for (int i=0; i<=25; i++){
		if ((1<<i)>=x) return i;
	}
}

bool tav2(ll x){
	while (x%2==0) x/=2;
	return x==1;
}

map<int, int> prime;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	debug(f(1));
	debug(f(2));
	debug(f(3));
	debug(f(4));
	debug(tav2(1));
	debug(tav2(2));
	debug(tav2(3));
	debug(tav2(4));
	
	cin>>n;
	if (n==1){
		cout<<"1 0"<<endl;
		return 0;
	}
	ll tmp=n;
	for (ll i=2; i*i<=tmp; i++){
		while (tmp%i==0){
			tmp/=i;
			prime[i]++;
		}
	}
	if (tmp>1) prime[tmp]++;
	
	ll ans=1, mx=0, flag=0, out=0;
	for (pii p:prime){
		int pr=p.first, c=p.second;
		mx=max(mx, (ll)c);
		ans*=pr;
	}
	for (pii p:prime){
		int c=p.second;
		if (c!=mx){
			flag=1;
			break ;
		}
	}
	debug(flag);
	debug(mx);
	if (!tav2(mx)) flag=1;
	debug(flag);
	
	cout<<ans<<' '<<f(mx)+flag<<endl;
	
	
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