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
const int Maxn = 1e6 + 10;
const int Inf = 1e7;
const ll Log = 30;


int seg[4 * Maxn];
int lazy[4 * Maxn];

void shift(int id){
	if(lazy[id] == 0) return ;
	for(int i = 0; i <= 1; i++){
		lazy[id << 1 | i] += lazy[id];
		seg[id << 1 | i] += lazy[id];
	}
	lazy[id] = 0;
}

void add(int id, int val, int l, int r, int L, int R){
	if(r <= L || l >= R) return ;
	if(l <= L && R <= r){
		seg[id] += val;
		lazy[id] += val;
		return ;
	}
	int mid = (L + R) >> 1;
	shift(id);
	add(id << 1, val, l, r, L, mid);
	add(id << 1 | 1, val, l, r, mid, R);
	seg[id] = min(seg[id << 1], seg[id << 1 | 1]);
	return ;
}

int get_min(int id, int l, int r, int L, int R){
	if(r <= L || l >= R) return Inf;
	if(l <= L && R <= r){
		return seg[id];
	}
	int mid = (L + R) >> 1;
	shift(id);
	return min(get_min(id << 1, l, r, L, mid),
		get_min(id << 1 | 1, l, r, mid, R));
}

ll ans;
bool BS(int id, int L, int R){
	if(seg[id] >= 0) {
		ans = L;
		return true;
	}
	//cerr << L << " " << R << " " << seg[id] <<'\n';
	if(L + 1 == R) return false;
	shift(id);
	int mid = (L + R) >> 1;
	bool res = BS(id << 1 | 1, mid, R);
	if(res){
		BS(id << 1, L, mid);
		return false;
	}
	return false;
}

int N = 1000002;
ll a[Maxn], b[Maxn];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= m; i++) cin >> b[i];
	for(int i = 1; i <= n; i++) add(1, -1, 1, a[i] + 1, 1, N);
	for(int i = 1; i <= m; i++) add(1, 1, 1, b[i] + 1, 1, N);
	ll q;
	cin >> q;
	ll t, ind, v;
	for(int i = 1; i <= q; i++){
		cin >> t >> ind >> v;
		if(t == 1){
			add(1, 1, 1, a[ind] + 1, 1, N);
			a[ind] = v;
			add(1, -1, 1, a[ind] + 1, 1, N);
		} else {
			add(1, -1, 1, b[ind] + 1, 1, N);
			b[ind] = v;
			add(1, 1, 1, b[ind] + 1, 1, N);
		}
		//cerr << get_min(1, 5, 5 + 1, 1, N) << "s\n";
		ans = -1;
		BS(1, 1, N);
		//cerr << ans << '\n';
		cout << (ans == 1 ? -1 : ans - 1) << '\n';	
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