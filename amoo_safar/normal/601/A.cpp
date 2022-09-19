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
const ll MAXN = (ll) 4e2 + 10;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

ll dis[MAXN];
map<pll, ll> ma;
queue<ll> q;

ll road(ll u, ll v){
	return (u == v ? -1 : ma[{u, v}]);
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	fill(dis, dis + MAXN, INF);
	
	ll n, m;
	cin >> n >> m;
	ll u, v;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		ma[{u, v}] = 1;
		ma[{v, u}] = 1;
	}
	
	q.push(1);
	dis[1] = 0;
	
	ll type = 1 - road(1, n);
	
	while(q.size()){
		for(int i = 1; i <= n; i++){
			if((road(q.front(), i) == type) and (dis[i] == INF)){
				q.push(i);
				dis[i] = dis[q.front()] + 1;
			}
		}
		q.pop();
	}
	
	
	cout << (dis[n] == INF ? -1 : dis[n]) << '\n';
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