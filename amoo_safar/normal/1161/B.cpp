#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) //cerr << #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 1e9 + 7;
const ll MAXN = (ll) 3e5 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

ll n, m;
vector<pll> A;
vector<ll> G[MAXN];

bool check(ll x){
	debug(x);
	if(x == n) return false;
	for(int i = 0; i < n; i++){
		ll j = (i + x) % n;
		ll sz = G[i].size();
		if(sz != G[j].size()) return false;
		for(int k = 0; k < sz; k++){
			if(((G[i][k] + x) % n) != G[j][k]){
				if(x == 4){
					debug(i); debug(k);
					debug(G[i][k]);
					debug(G[j][k]);
				}
				return false;			
			}
		}
	}
	return true;
}

ll nw;

ll dist(ll x){
	if(x >= nw) return x - nw;
	return n - (nw - x);
}

bool CMP(ll i, ll j){
	return dist(i) < dist(j);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//ll n, m;
	cin >> n >> m;
	ll u, v;
	for(int i = 0; i<m; i++){
		cin >>u >> v;
		u--;
		v--;
		G[u].pb(v);
		G[v].pb(u);
	}
	nw = 2;
	debug(dist(10));
	for(int i = 0; i<n; i++){
		nw = i;
		sort(all(G[i]), CMP);
	}
	for(auto x : G[2]) debug(x);
	
	debug("l");
	bool f;
	for(int i = 1; i*i<= n; i++){
		if(n % i == 0){
			f = check(i) | check(n / i);
			if(f) return cout << "Yes", 0;
		}
	}
	//debug(check(4));
	cout << "No";
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