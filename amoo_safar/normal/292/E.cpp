#include <bits/stdc++.h>

#define pb push_back
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
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

ll a[MAXN], b[MAXN];
pll query[MAXN];

ll seg[4 * MAXN];
void update(int id, int l, int r, int val, int L, int R){
	if(r <= L || R <= l) return ;
	if(l <= L && R <= r){
		seg[id] = val;
		return ;
	}
	int mid = (L + R) >> 1;
	update(id << 1, l, r, val, L, mid);
	update(id << 1 | 1, l, r, val, mid, R);
	return ;
}
ll get(int id, int ind, int L, int R){
	if(ind < L || R <= ind) return 0;
	if(ind <= L && R <= ind + 1) return seg[id];
	int mid = (L + R) >> 1;
	return max({seg[id],
		get(id << 1, ind, L, mid),
		get(id << 1 | 1, ind, mid, R)});
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	
	ll t, x, y, k;
	for(int i = 1; i <= m; i++){
		cin >> t;
		if(t == 1){
			cin >> x >> y >> k;
			query[i] = {x, y};
			update(1, y, y + k, i, 1, n + 1);
		} else {
			cin >> x;
			ll last = get(1, x, 1, n + 1);
			if(last == 0) cout << b[x] << '\n';
			else cout << a[query[last].F + x - query[last].S ] << '\n';
		}
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