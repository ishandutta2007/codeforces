#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll Mod = 1000000007LL;
const int Maxn = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll p[Maxn], a[Maxn], mx[Maxn];

ll get(ll u){
	if(p[u] == u) return u;
	return p[u] = get(p[u]);
}
bool merge(ll u, ll v){
	u =get(u);
	v = get(v);
	if(u == v) return false;
	p[u] = v;
	mx[v] = max(mx[v], mx[u]);
	return true;
}

ll d[Maxn];
ll mk[Maxn];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, k;
	cin >> n >> k;
	iota(p, p + Maxn, 0);
	ll u, v;
	ll ans = 0;
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
		mx[a[i]] ++;
	}
	for(int i = 0; i < n; i++){
		if(!mk[a[i]]) d[i] ++;
		mk[a[i]] = 1;
	}
	memset(mk, 0, sizeof mk);
	for(int i = n - 1; i >= 0; i--){
		if(!mk[a[i]]) d[i] --;
		mk[a[i]] = 1;
	}
	ll s = 0;
	for(int i = 0; i < n - 1; i++){
		s += d[i];
		if(s > 0) merge(a[i], a[i + 1]);
		//if(s > 0) cerr << i << ' ';
	}
	//for(int i = 1; i < n; i++) merge(a[i], a[i - 1]);
	ll sm = 0;
	for(int i = 0 ; i < Maxn; i++) if(p[i] == i) sm += mx[i];
	cout << n - sm;
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