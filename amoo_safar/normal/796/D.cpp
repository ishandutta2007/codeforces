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
const ll MAXN = (ll) 3e5 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

ll rm[MAXN];
bool mark[MAXN];
vector<pll> G[MAXN];
queue<ll> q;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, k, d, c;
	cin >> n >> k >> d;
	
	for(int i = 0; i < k; i++){
		cin >> c;
		if(!mark[c]){
			mark[c] = true;
			q.push(c);
		}
	}
	ll u, v;
	for(int i = 1; i < n; i++){
		cin >> u >> v;
		G[u].pb({v, i});
		G[v].pb({u, i});
	}
	
	cout << q.size() - 1 << '\n';
	
	ll adj, ind;
	while(q.size()){
		for(auto ed : G[q.front()]){
			adj = ed.F; ind = ed.S;
			if(!mark[adj]){
				rm[ind] = 1;
				q.push(adj);
				mark[adj] = true;
			}
		}
		q.pop();
	}
	for(int i = 1; i < n; i++) if(rm[i] == 0) cout << i << " ";
	cout << '\n';
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