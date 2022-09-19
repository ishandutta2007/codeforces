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
const ll MAXN = (ll) 5e3 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

map<ll, ll> mp;
map<pll ,ll> mp2;

ll a[MAXN];
ll c[MAXN];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, k;
	cin >> n >> k;
	for(int i = 0;i<n;i++)cin >> a[i];
	for(int i = 0; i < k;i++) c[i] = i + 1;
	for(int i = 0; i < n; i++) mp2[{a[i],c[i]}]++;
	ll fl;
	for(int i = k; i < n; i++){
		fl = 0;
		for(int j = 1; j <= k; j++){
			if(mp2.count({a[i], j}) == 0){
				mp2[{a[i], j}] ++;
				c[i] = j;
				fl = 1;
				break;
			}
		}
		if(fl == 0) return cout << "NO", 0;
	}
	cout << "YES\n";
	for(int i = 0;i<n;i++) cout << c[i] << " ";
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