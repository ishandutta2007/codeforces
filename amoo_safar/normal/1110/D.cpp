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
const ll MAXN = (ll) 1e6 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-12;

ll a[MAXN], cnt[MAXN];
ll dp[2][9][9], mx[MAXN][9];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m;
	cin >> n >> m;
	ll v;
	ll ans = 0;
	for(int i = 0;i<n;i++){
		cin >> v;
		cnt[v] ++;
	}
	for(int k = 0;k<2;k++) for(int i = 0;i<9;i++) for(int j = 0;j<9;j++) dp[k][i][j] = -INF;
	dp[0][0][0]= 0;
	ll an2 = 0;
	for(int i = 1; i <= m; i++){
		ll ii = i&1;
		for(int j = 0; j < 9; j++)
			for(int k = 0; k < 6; k++){
				dp[ii][j][k] = -INF;
				for(int cn = 0; cn < 3; cn ++){
					if(cn + j > cnt[i] or cn + k > cnt[i - 1]){
						continue;
					}
					for(int t = cn; t < 6; t++) dp[ii][j][k] = max(dp[ii][j][k], dp[ii ^ 1][cn + k][cn] + cn + (cnt[i] - cn - j) / 3 );
					an2 = max(an2, dp[ii][j][k]);
					
				}
			}	
	}
	cout << an2;
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