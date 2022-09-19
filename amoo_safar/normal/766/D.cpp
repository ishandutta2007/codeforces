#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 1e5 + 10;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

ll par[MAXN], com[MAXN];

ll get_par(ll node){
	ll x = par[node];
	if(x == node) return node;
	ll y = get_par(x);
	if(com[x] == com[node]) com[node] = 0;
	else com[node] = 1;
	par[node] = y;
	return par[node];
}

void merge(ll a, ll b, ll t){
	ll x = get_par(a);
	ll y = get_par(b);
	if(x == y) return ;
	if( (com[a] + t + com[b]) % 2 == 1 ) com[x] = 1;
	else com[x] = 0;
	par[x] = y;
}
map<str, ll> ma;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n, m, q;
	cin >> n >> m >> q;
	str s, t;
	for(int i = 1; i <= n; i++){
		cin >> s;
		ma[s] = i;
		par[i] = i;
	}
	ll re, u, v;
	for(int i = 0; i < m; i++){
		cin >> re >> s >> t;
		u = ma[s];
		v = ma[t];
		re--;
		if((get_par(u) == get_par(v)) and ((com[u] + com[v] + re) % 2 == 1)) cout << "NO\n";
		else {
			cout << "YES\n";
			if(get_par(u) == get_par(v)) continue;
			merge(u, v, re);
		}
	}
	for(int i = 0; i < q; i++){
		cin >> s >> t;
		u = ma[s];
		v = ma[t];
		if(get_par(u) != get_par(v)) cout << "3\n";
		else if(com[u] == com[v]) cout << "1\n";
		else cout << "2\n";
	}
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