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

const ll MOD = (ll) 1e9 + 7;
const ll MAXN = (ll) 5e3 + 10;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

ll dis[MAXN][MAXN], col[MAXN];
pll po[MAXN];

ll n;

ll dfs(ll node, ll d){
	ll ans = 1;
	for(int i = 0; i < n; i++){
		if(dis[node][i] > d){
			if(col[i] == col[node]){
				return 0;
			}
			if(col[i] == 0) {
				col[i] = 3 - col[node];
				ans = dfs(i, d);
				if(ans == 0) return 0;
			}
		}
	}
	return 1;
}

ll check(ll d){
	ll ans;
	ll coms = 0;
	fill(col, col + n, 0);
	for(int i = 0; i < n; i++){
		if(col[i] != 0) continue;
		col[i] = 1;
		ans = dfs(i, d);
		if(ans == 0) return 0;
		coms ++;
	}
	return coms;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//ll n;
	cin >> n;
	for(int i = 0;i<n;i++){
		cin >> po[i].F >> po[i].S;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++) dis[i][j] = abs(po[i].F - po[j].F) + abs(po[i].S - po[j].S);
	}
	
	ll dw = -1;
	ll up = 10000;
	ll mid;
	while(dw + 1 < up){
		mid = (dw + up) / 2;
		if(check(mid) == 0) dw = mid;
		else up = mid;
	}
	ll f = 1;
	ll ch = check(up);
	for(int i = 0;i<ch;i++){
		f *= 2ll;
		f %= MOD;
	}
	cout << up << '\n' << f;
	
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