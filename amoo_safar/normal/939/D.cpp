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
const ll MAXN = (ll) 2e5 + 10;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

vector<pll> out;

ll par[26];
ll get_par(ll node){
	ll x = par[node];
	if(x == node) return node;
	par[node] = get_par(x);
	return par[node];
}
void merge(ll a, ll b){
	ll x = get_par(a);
	ll y = get_par(b);
	if(x == y) return ;
	out.pb(mp(x, y));
	par[x] = y;
}



int main(){
	for(int i =0;i<26;i++) par[i] = i;
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin >> n;
	str s, t;
	cin >> s >> t;
	for(int i =0;i<n;i++){
		merge(s[i]-'a',t[i]-'a');
	}
	cout << out.size() << endl;
	for(auto sp : out) cout << (char)('a' + sp.F) << " " << (char)('a' + sp.S) << endl;
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