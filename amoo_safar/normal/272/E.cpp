#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 3e5 + 10;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;


ll part[MAXN];

vector<ll> g[MAXN];
queue<ll> bfsq;

bool change(ll node){
	ll ene = 0;
	for(auto adj : g[node]){
		if(part[node] == part[adj]){
			ene ++;
		}
	}
	if(ene >= 2) return true;
	return false;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n, m, u, v;
	scanf("%lld %lld", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%lld %lld", &u, &v);
		u--;
		v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	
	for(int i = 0; i < n; i++){
		if(change(i)) bfsq.push(i);
	}
	
	while(bfsq.size() != 0){
		if(!change(bfsq.front())){
			bfsq.pop();
			continue;
		}
		part[bfsq.front()] = 1 - part[bfsq.front()];
		for(auto adj : g[bfsq.front()]){
			if(part[adj] == part[bfsq.front()]){
				if(change(adj)) bfsq.push(adj);
			}
		}
		bfsq.pop();
	}
	
	for(int i = 0; i < n; i++) printf("%lld", part[i]);
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