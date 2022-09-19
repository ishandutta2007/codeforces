#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 1e9 + 7;
const ll MAXN = (ll) 1e6 + 10;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

ll dp[MAXN][3];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	str s;
	getline(cin, s);
	if(s[0] == '?'){
		dp[1][0] = 1;
		dp[1][1] = 1;
		dp[1][2] = 1;
	}
	if(s[0] == '*'){
		dp[1][0] = 0;
		dp[1][1] = 0;
		dp[1][2] = 1;
	}
	if(s[0] == '0'){
		dp[1][0] = 1;
		dp[1][1] = 0;
		dp[1][2] = 0;
	}if(s[0] == '1'){
		dp[1][0] = 0;
		dp[1][1] = 1;
		dp[1][2] = 0;
	}
	if(s[0] == '2'){
		dp[1][0] = 0;
		dp[1][1] = 0;
		dp[1][2] = 0;
	}
	for(int i = 2; i <= s.size(); i++){
		if(s[i - 1] == '?'){
			dp[i][2] = dp[i - 1][1] + dp[i-1][2];
			dp[i][1] = dp[i - 1][0] + dp[i-1][2];
			dp[i][0] = dp[i - 1][0] + dp[i-1][2];
		}
		if(s[i-1] == '0'){
			dp[i][0] = dp[i-1][0];
		}
		if(s[i-1] == '1'){
			dp[i][0] = dp[i-1][2];
			dp[i][1] = dp[i-1][0];
		}
		if(s[i-1] == '2'){
			dp[i][1] = dp[i - 1][2];
		}
		if(s[i-1] == '*'){
			dp[i][2] = dp[i - 1][1] + dp[i-1][2];
		}
		for(int j = 0; j < 3; j++) dp[i][j] %= MOD;
	}
	
	cout << (dp[s.size()][0] + dp[s.size()][2]) % MOD;
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