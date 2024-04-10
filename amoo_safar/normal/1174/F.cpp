#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " = " << x << '\n'; 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 2e5 + 10;
const ll N = 1e5 + 100;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;


ll par[MAXN], sd, dep[MAXN];

ll mk[MAXN];
vector<ll> rem, G[MAXN];

ll sz;

pll cent(ll u){
	mk[u] = 1;
	ll up = sz - 1;
	ll big = 0;
	pll res;
	for(auto adj : G[u]){
		if(mk[adj] == 1) continue;
		res = cent(adj);
		if(res.S != 0) return {0, res.S};
		up -= res.F;
		big = max(big, res.F);
	}
	big = max(big, up);
	return {sz - up, (big + big <= sz ? u : 0)};
}

bool is_par(ll u){
	cout << "d " << u << endl;
	ll res;
	cin >> res;
	if(res == 0){
		cout << "! " << u << endl;
		exit(0);
	}
	return (res + dep[u] == sd);
}

ll ask(ll node){
	if(is_par(node)){
		cout << "s " << node << endl;
		ll res;
		cin >> res;
		return res;
	}
	return par[node];
}

void DFS(ll u){
	mk[u] = 1;
	rem.pb(u);
	for(auto adj : G[u]) if(mk[adj] == 0) DFS(adj);
}

void DFS2(ll u, ll p, ll d = 0){
	par[u] = p;
	dep[u] = d;
	for(auto adj : G[u]){
		if(adj == p) continue;
		DFS2(adj, u, d + 1);
	}
}

void play(){
	if(rem.size() == 0) exit(0);
	sz = rem.size();
	if(sz == 1){
		cout <<"! " << rem.back() << endl;
		exit(0);
	}
	
	for(auto x : rem) mk[x] = 0;
	
	ll root = rem.back();
	ll roid = cent(root).S;
	//debug(roid);
	ll res = ask(roid);
	//debug(roid);
	if(res == -1){
		cout << "2 " << roid << endl;
		cin >> root;
		if(root == -2) exit(0);
		return ;
	}
	for(auto x : rem) mk[x] = 0;
	mk[roid] = 1;
	rem.clear();
	DFS(res);
	play();
}


int MAIN(){
	ll n;
	cin >> n;
	
	rem.clear();
	for(int i = 1; i <= n; i++) rem.pb(i);
	ll u, v;
	for(int i = 1; i < n; i++){
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}
	
	
	cout << "d 1" << endl;
	cin >> sd;
	if(sd == 0){
		cout << "! 1" << endl;
		return 0;
	}
	DFS2(1, 1);
	
	play();
	for(int i = 1; i <= n; i++) G[i].clear();
	for(int i = 1; i <= n; i++) mk[i] = 0;
	return 0;
}

int main(){
	ll T;
	//cin >> T;
	T = 1;
	while(T--) MAIN();
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