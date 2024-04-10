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
const ll MAXN = (ll) 5e2 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

vector<pll> con[26];
ll dp1[MAXN][MAXN][26], dp2[MAXN][MAXN][26], dp3[MAXN][MAXN];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	memset(dp3, 31, sizeof dp3);
	
	str s, t;
	cin >> s >> t;
	ll n = s.size();
	ll m = t.size();
	ll k;
	cin >> k;
	str spe;
	for(int i = 0; i < k; i++){
		cin >> spe;
		con[spe[0] - 'a'].pb({spe[3] - 'a', spe[4] - 'a'});
	}
	
	for(int i = 0; i < n; i++) dp1[i][i + 1][s[i] - 'a'] = 1;
	for(int l = 2; l <= n; l++){
		for(int i = 0; i + l <= n; i++){
			ll j = i + l;
			for(int k = 0; k < 26; k++){
				for(int mid = i + 1; mid < j; mid ++){
					for(auto sp : con[k]){
						if(dp1[i][mid][sp.F] == 1 and dp1[mid][j][sp.S] == 1) dp1[i][j][k] = 1;
					}
				}
			}
		}
	}
	
	for(int i = 0; i < m; i++) dp2[i][i + 1][t[i] - 'a'] = 1;
	for(int l = 2; l <= m; l++){
		for(int i = 0; i + l <= m; i++){
			ll j = i + l;
			for(int k = 0; k < 26; k++){
				for(int mid = i + 1; mid < j; mid ++){
					for(auto sp : con[k]){
						if(dp2[i][mid][sp.F] == 1 and dp2[mid][j][sp.S] == 1) dp2[i][j][k] = 1;
					}
				}
			}
		}
	}
	dp3[0][0] = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			for(int i2 = 0; i2 < i; i2++){
				for(int j2 = 0; j2 < j; j2++){
					for(int k = 0; k < 26; k++){
						if(dp1[i2][i][k] == 1 and dp2[j2][j][k] == 1) dp3[i][j] = min(dp3[i][j], dp3[i2][j2] + 1);
					}
				}
			}
		}
	}
	
	cout << (dp3[n][m] == INF ? -1 : dp3[n][m]);
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