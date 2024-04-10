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
const ll MAXN = (ll) 2e5 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

ll dp[MAXN][3];
pll par[MAXN][3];
vector<char> an;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	str l = "RGB";
	ll n;
	cin >> n;
	str s;
	cin >> s;
	s = '!' + s;
	
	memset(dp, 31 ,sizeof dp);
	dp[0][0] = dp[0][1] = dp[0][2] = 0;
	ll rq;
	for(int i = 1; i <= n; i++){
		for(int j = 0 ;j < 3; j++){
			for(int k =0;k<3;k++){
				if(j == k) continue;
				rq = dp[i - 1][k] + (l[j] == s[i] ? 0 : 1);
				if(rq < dp[i][j]){
					par[i][j] = make_pair(i-1, k);
					dp[i][j] = rq;
				}
			}
		}
	}
	ll la = 0;
	for(int i = 0;i<3;i++){
		if(dp[n][i] < dp[n][la]) la = i;
	}
	cout << dp[n][la] << '\n';
	ll x = n;
	while(x != 0){
		an.pb(l[la]);
		la = par[x][la].S;
		x--;
	}
	for(int i = n - 1; i>=0;i--) cout << an[i];
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