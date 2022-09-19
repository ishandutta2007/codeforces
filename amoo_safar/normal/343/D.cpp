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
const ll MAXN = (ll) 5e5 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

vector<int> G[MAXN];
int t = 1;

int num[MAXN], sub[MAXN], par[MAXN];

void DFS(ll u, ll p){
	par[u] = p;
	num[u] = t++;
	sub[u] = 1;
	for(auto adj : G[u]){
		if(adj == p) continue;
		DFS(adj, u);
		sub[u] += sub[adj];	
	}
}

int seg[4 * MAXN];
int lazy[4 * MAXN];

void shift(int id){
	if(lazy[id] == -1) return ;
	for(int i = 0; i <= 1; i++){
		lazy[id << 1 | i] = lazy[id];
		seg[id << 1 | i] = lazy[id];
	}
	lazy[id] = -1;
}

void update(int id, int val, int l, int r, int L, int R){
	//debug(l);
	//debug(r);
	//debug(val);
	if(r <= L || l >= R) return ;
	if(l <= L && R <= r){
		seg[id] = val;
		lazy[id] = val;
		return ;
	}
	int mid = (L + R) >> 1;
	shift(id);
	update(id << 1, val, l, r, L, mid);
	update(id << 1 | 1, val, l, r, mid, R);
	seg[id] = min(seg[id << 1], seg[id << 1 | 1]);
	return ;
}

ll get_min(int id, int l, int r, int L, int R){
	if(r <= L || l >= R) return 1;
	if(l <= L && R <= r){
		return seg[id];
	}
	int mid = (L + R) >> 1;
	shift(id);
	return min(get_min(id << 1, l, r, L, mid),
		get_min(id << 1 | 1, l, r, mid, R));
}

ll n;

void empty(ll v){
	update(1, 0, num[v], num[v] + 1, 1, n + 1);
}

void fill(ll v){
	update(1, 1, num[v], num[v] + sub[v], 1, n + 1);
}

ll type(ll v){
	return get_min(1, num[v], num[v] + sub[v], 1, n + 1);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	ll u, v;
	for(int i = 1; i < n; i++){
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}
	DFS(1, -1);
	ll q, t;
	cin >> q;
	ll y = 0;
	for(int i = 1; i <= q; i++){
		cin >> t >> v;
		if(t == 1){
			if(v != 1) if(type(par[v]) == 0) empty(par[v]);
			fill(v);
		} else if(t == 2) {
			empty(v);
		} else {
			y += 1;
			/*if(y == 9117) {
				cout << "0\n";
				continue;
			}*/
			if(v != 1) if(type(par[v]) == 0) empty(par[v]);
			cout << type(v) << '\n';
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