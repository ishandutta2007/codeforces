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
const ll MAXN = (ll) 3e3 + 10;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

ll nw1[MAXN][MAXN], nw2[MAXN][MAXN];
str ma[MAXN];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> ma[i]; 
	
	if(ma[1][0] == '.') nw1[2][1] = 1;
	if(ma[0][1] == '.') nw2[1][2] = 1;
	
	for(int i = 2; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(i == 2 and j == 1) continue;
			if(ma[i - 1][j - 1] == '#') nw1[i][j] = 0;
			else nw1[i][j] = (nw1[i - 1][j] + nw1[i][j - 1])  % MOD;
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 2; j <= m; j++){
			if(i == 1 and j == 2) continue;
			if(ma[i - 1][j - 1] == '#') nw2[i][j] = 0;
			else nw2[i][j] = (nw2[i - 1][j] + nw2[i][j - 1])  % MOD;
		}
	}
	
	ll ans = (nw1[n][m] * nw2[n][m]) % MOD;
	ans = ans - (nw1[n - 1][m] * nw2[n - 1][m]);
	ans %= MOD;
	ans = ans - (nw1[n][m - 1] * nw2[n][m - 1]);
	ans %= MOD;
	ans = ans - 2 * (nw1[n - 1][m] * nw2[n][m - 1]);
	ans %= MOD;
	cout << (ans + MOD) % MOD;
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