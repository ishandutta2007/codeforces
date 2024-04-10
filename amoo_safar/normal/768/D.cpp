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

const ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 2e5 + 10;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-7;

ld dp[10010][1010];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ld k;
	ll q;
	cin >> k >> q;
	
	dp[1][1] = 1.0;
	for(int i = 2; i <= 10000; i++){
		for(int j = 1; j <= k; j++){
			dp[i][j] = (dp[i - 1][j] * (j / k)) + (dp[i - 1][j - 1] * ((k - j + 1) / k));
		}
	}
	
	ll p;
	for(int i = 0; i < q; i++){
		cin >> p;
		for(int j = 1; j <= 10000; j++){
			if(p - 2000 * dp[j][(ll)k] < EPS){
				cout << j << endl;
				break;
			}
		}
	}

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