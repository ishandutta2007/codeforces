#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 1e9 + 7;
const ll MAXN = (ll) 2e5 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;
const ll LOG = (ll) 30;

ll a[MAXN], b[MAXN], n;
ll c[2 * MAXN], wh[MAXN], mk[MAXN];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		mk[a[i]] = 1;
		wh[a[i]] = 1;
	}
	ll fl = 0;
	for(int i = 1; i <= n; i++){
		cin >> b[i];
		wh[b[i]] = i + 1;
	}
	
	ll ans = 1;
	for(int i = 1; i <= n; i++){
		ans = max(ans, wh[i] - i + 1);
	}
	//cout << ans + n;
	//debug(ans);
	if(wh[1] != 0){
		for(int i = wh[1] - 1, j = 1; i <= n; i++, j++) if(b[i] != j) fl = 1;
		if(fl == 1) return cout << ans + n - 1, 0;
		ll ex = wh[1] - 2;
		ll fl2 = 0;
		ll p = 1; ll ls = b[n];
		for(int i = 0; i < ex; i++){
			if(mk[ls + 1] == 0){
				fl2 = 1;
				break;
			}
			mk[b[p]] = 1;
			p++;
			ls ++;
		}
		if(fl2 == 0) cout << ex;
		else cout << ans + n - 1;
	} else cout << ans + n - 1;
	
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