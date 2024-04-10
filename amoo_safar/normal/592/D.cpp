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
const ll MAXN = (ll) 123456 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

ll in[MAXN], dan[MAXN];

set<ll> g[MAXN];

queue<ll> q;

void rem(ll node){
	for(auto adj : g[node]) g[adj].erase(node);
	g[node].clear();
}

pll DFS(ll node, ll par){
	ll ans = 0;
	ll far = node;
	pll res;
	for(auto adj : g[node]){
		if(adj == par) continue;
		res = DFS(adj, node);
		if(ans == res.S + 1){
			if(res.F < far) far = res.F;
		}
		if(ans < res.S + 1){
			ans = res.S + 1;
			far = res.F;
		}
	}
	return {far, ans};
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n, m;
	cin >> n >> m;
	ll e = n - 1;
	ll u, v;
	for(int i = 1; i < n; i++){
		cin >> u >> v;
		g[u].insert(v);
		g[v].insert(u);
	}
	ll ci;
	if(m == 1){
		cin >> ci;
		cout << ci << endl << 0 << endl;
		return 0;
	}
	ll last;
	for(int i = 0; i < m; i++){
		cin >> ci;
		dan[ci] = 1;
		last = ci;
	}
	
	for(int i = 1; i <= n; i++){
		if(g[i].size() == 1) q.push(i);
	}
	
	ll fr, par;
	while(q.size()){
		fr = q.front();
		//debug(fr);
		q.pop();
		
		if(dan[fr] == 1) continue;
		par = *g[fr].begin();
		rem(fr);
		e--;
		if(g[par].size() == 1){
			q.push(par);
		}
	}
	
	debug("c1");
	pll res = DFS(last, -1);
	pll ans = DFS(res.F, -1);
	cout << min(res.F, ans.F) << endl;
	cout << 2 * e - ans.S;
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