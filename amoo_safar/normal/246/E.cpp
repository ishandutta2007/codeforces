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

map<str, ll> convert;
ll par[MAXN], dep[MAXN], ans[MAXN], name[MAXN];
map<ll, vector<pll> > que;
vector<ll> g[MAXN];
vector<pll> query[MAXN];

map<ll, set<ll> > *sub_tree[MAXN];


void set_dep(ll node){
	if(dep[node] != -1) return ;
	set_dep(par[node]);
	dep[node] = dep[par[node]] + 1;
}

ll DFS(ll node){
	ll big_child = -1;
	ll max_size = 0;
	ll sz;
	for(auto adj : g[node]){
		sz = DFS(adj);
		if( sz > max_size ){
			max_size = sz;
			big_child = adj;
		}
	}
	
	ll siz = max_size + 1;
	
	if( big_child == -1 ){
		sub_tree[node] = new map<ll, set<ll> > ();
		(*sub_tree[node])[dep[node]].insert( name[node] );
	} else {
		sub_tree[node] = sub_tree[big_child];
		(*sub_tree[node])[dep[node]].insert( name[node] );
	}
	
	for(auto adj : g[node]){
		if(adj == big_child) continue;
		for(auto x : (*sub_tree[adj])){
			for(auto y : x.S ){
				if( (*sub_tree[node])[x.F].find(y) == (*sub_tree[node])[x.F].end() ){
					(*sub_tree[node])[x.F].insert(y);
					siz ++;
				}
			}
		}
	}
	
	if(node == 0) return siz;
	for(auto q : query[node]){
		ans[ q.S ] = (*sub_tree[node])[ dep[node] + q.F ].size();
	}
	
	return siz;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin >> n;
	ll last_name = 1;
	str s;
	for(int i = 1; i <= n; i++) {
		cin >> s >> par[i];
		if(convert[s] == 0){
			convert[s] = last_name;
			last_name ++;
		}
		name[i] = convert[s];
	}
	for(int i = 1; i <= n; i++) g[par[i]].pb(i);
	
	memset(dep, -1, sizeof dep);
	dep[0] = 0;
	for(int i = 0; i <= n; i++) set_dep(i);
	ll m;
	cin >> m;
	
	ll v, p;
	for(int i = 0; i < m; i++){
		cin >> v >> p;
		query[v].pb({p, i});
	}
	
	DFS(0);
	//for(auto x : (*sub_tree[1])) cerr << x.F << " " << x.S << '\n';

	for(int i = 0; i < m; i++) cout << ans[i] << '\n';
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