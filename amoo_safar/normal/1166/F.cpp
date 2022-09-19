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

set<int> st[MAXN];
int p[MAXN];

int par(int u){
	if(p[u] == u) return u;
	return p[u] = par(p[u]);
}

void merge(int u, int v){
	u = par(u);
	v = par(v);
	if(u == v) return ;
	if(st[u].size() > st[v].size()) swap(u, v);
	for(auto x : st[u]) st[v].insert(x);
	st[u].clear();
	p[u] = v;
}

map<pll, int> mp;

void add(int u, int v, int z){
	if(mp.count({u, z})) merge(v, mp[{u, z}]);
	mp[{u, z}] = v;
	st[par(u)].insert(v);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for(int i = 0; i < MAXN; i++) p[i] = i;
	for(int i = 1; i < MAXN; i++) st[i].insert(i);
	int n, m, c, q;
	cin >> n >> m >> c >> q;
	int u, v, z;
	for(int i = 0; i < m; i++){
		cin >> u >> v >> z;
		add(u, v, z);
		add(v, u, z);
	}
	char t;
	for(int i = 0; i < q; i++){
		cin >> t;
		if(t == '+'){
			cin >> u >> v >> c;
			add(u, v, c);
			add(v, u, c);
		} else {
			cin >> u >> v;
			cout << (st[par(u)].count(v) ? "Yes" : "No") << '\n';
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