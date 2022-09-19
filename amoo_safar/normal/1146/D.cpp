#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 1e9 + 7;
const ll MAXN = (ll) 2e5 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

ll mk[MAXN];
ll ans = 0;
ll a, b;
vector<ll> G[MAXN];

void DFS(ll u){
	if(mk[u]) return ;
	ans ++;
	mk[u] =1 ;
	for(auto adj : G[u]) if(mk[adj] == 0) DFS(adj);
	return ;
}


void add(ll x){
	if(x >= b) G[x].pb(x - b);
	
	if(x >= a){
		G[x - a].pb(x);
		if(mk[x-a] == 1) DFS(x);
	}
}

int main(){
	ll m;
	cin >> m >> a >> b;
	ll s = a + b;
	ll d = __gcd(a, b);
	DFS(0);
	ll an = 1;
	ll y = min(m, a + b + 100ll);
	for(int i = 1; i <= y; i++) {

		add(i);
		an += ans;
        //cout << ans << '\n';
	}
	//cout << y << " ";
	if(y == m) return cout << an << '\n', 0;
	ll x = (m - y) / d;
  	ll st = y + 1;
  	ll an2 = an;
  	y++;
  	while(y <= m){
		  if(y / d != (y - 1) / d) break;
		  else{
		  	an2 += (y / d);
		  	an2 ++;
		  	y++;
		  }
	}
  	while(y <= m){
		  if(m / d != (m + 1) / d) break;
		  else{
		  	an2 += (m / d);
		  	an2 ++;
			  m--;
		  }
	}
  	
  	if(y == m) return cout << an2, 0;
  	ll f = (y) / d;
  	f++;
  	ll se = m / d;
  	se ++;
	  ll z = (f + se) * (se - f + 1) / 2ll;
  	an2 += (d * z);
  	cout << an2;
  
  return 0;
}

/*

                                 ____              ,----..               ,----..
   ,---,                       ,'  , `.           /   /   \             /   /   \
  '  .' \                   ,-+-,.' _ |          /   .     :           /   .     :
 /  ;    '.              ,-+-. ;   , ||         .   /   ;.  \         .   /   ;.  \
:  :       \            ,--.'|'   |  ;|        .   ;   /  ` ;        .   ;   /  ` ;
:  |   /\   \          |   |  ,', |  ':        ;   |  ; \ ; |        ;   |  ; \ ; |
|  :  ' ;.   :         |   | /  | |  ||        |   :  | ; | '        |   :  | ; | '
|  |  ;/  \   \        '   | :  | :  |,        .   |  ' ' ' :        .   |  ' ' ' :
'  :  | \  \ ,'        ;   . |  ; |--'         '   ;  \; /  |        '   ;  \; /  |
|  |  '  '--'          |   : |  | ,             \   \  ',  /          \   \  ',  /
|  :  :                |   : '  |/               ;   :    /            ;   :    /
|  | ,'                ;   | |`-'                 \   \ .'              \   \ .'
`--''                  |   ;/                      `---`                 `---`
                       '---'

*/