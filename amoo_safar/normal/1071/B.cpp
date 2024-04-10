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

const ll MOD = (ll) 1e9 + 7;
const ll MAXN = (ll) 2e3 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

pll side_adj[] = {{1, 0}, {0, 1}};
char c[MAXN][MAXN];
ll n, dp[MAXN][MAXN], in[MAXN][MAXN];

vector<pll> now, fut;

bool valid(ll i, ll j){
	return max(i, j) <= n;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(dp, 31, sizeof dp);
	ll k;
	cin >> n >> k;
	//debug("c-1");
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) cin >> c[i][j];
	
	char inf = (char) (255);
	
	for(int i = 0; i <= n + 1; i++){
		c[n + 1][i] = inf;
		c[i][n + 1] = inf;
	}
	//debug("c0");
	dp[0][1] = 0;
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + (c[i][j] == 'a' ? 0 : 1);
	//debug(dp[n][n]);
	if(dp[n][n] <= k){
		for(int i = 0; i < n + n - 1; i++) cout << 'a';
		return 0;
	}
	str ans = "";
	ll mx = 0;
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) if(dp[i][j] <= k) mx = max(mx, i + j - 1ll);
	for(int i = 0; i < mx; i++) ans += 'a';
	ll dia = mx;
	//debug(dia);
	for(int i = dia, j = 1; i > 0; i--, j++){
		if(!valid(i, j)) continue;
		if(dp[i][j] <= k) now.pb({i, j});
	}
	if(now.size() == 0){
		ans += c[1][1];
		now.pb({1, 1});
		mx = 1;
	}
	//debug(now.size());
	ll x, y, nx, ny;
	//debug("c1");
	ll mn;
	ll val;
	for(int d = mx + 1; d <= 2 * n - 1; d++){
		//debug(d);
		fut.clear();
		mn = 150;
		for(auto cell : now){
			x = cell.F; y = cell.S;
			for(auto del : side_adj){
				nx = x + del.F;
				ny = y + del.S;
				if(!valid(nx, ny)) continue;
				
				if( ( (ll)(c[nx][ny] - 'a') ) == mn){
					if(fut.size() == 0){
						fut.pb({nx, ny});
					} else if(fut.back() != make_pair(nx, ny)){
						fut.pb({nx, ny});
					}
				}
				if( ( (ll)(c[nx][ny] - 'a') ) < mn){
					fut.clear();
					fut.pb({nx, ny});
					mn = c[nx][ny] - 'a';
				}
			}
		}
		ans += ((char) (mn + 'a'));
		now.clear();
		for(auto x : fut) now.pb(x);
	}
	cout << ans;
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