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

vector<ll> G[MAXN];

ll a[MAXN], v[MAXN], h[MAXN], s[MAXN];

void DFS(ll u, ll p){
	if(s[u] == -1){
		ll mn = INF;
		for(auto adj : G[u]){
			if(adj == p) continue;
			mn = min(mn, s[adj] - s[p]);
		}
		if(mn < 0){
			cout << "-1\n";
			exit(0);
		}
		a[u] = (mn == INF ? 0 : mn);
		s[u] = s[p] + a[u];
	} else {
		a[u] = s[u] - s[p];
	}
	
	for(auto adj : G[u]){
		if(adj == p) continue;
		DFS(adj, u);
	}
	return ;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	ll v;
	for(int i = 2;i <= n;i++){
		cin >> v;
		G[i].pb(v);
		G[v].pb(i);
	}
	for(int i = 1;i<=n;i++) cin >> s[i];
	a[0] = 0;
	DFS(1,0);
	ll sm=0;
	for(int i = 1;i<=n;i++){
		sm +=a[i];
	}
	for(int i =1;i<=n;i++) cerr << a[i];
	cerr << '\n';
	cout << ((*min_element(a + 1, a + n + 1) ) < 0 ? -1 : sm);
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