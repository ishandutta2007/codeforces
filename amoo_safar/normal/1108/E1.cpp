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

ll n, m, a[MAXN], b[MAXN];
pll sg[MAXN];

void add(ll i){
	for(int x = sg[i].F; x <= sg[i].S; x++) b[x - 1] --;
}

void build(ll x){
	for(int i = 0; i < n; i++) b[i] = a[i];
	for(int i = 0; i < m; i++){
		if((x+1 < sg[i].F) or (sg[i].S < x+1)) add(i);
	}
}

vector<ll> an;

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int j = 0; j < m; j++) cin >> sg[j].F >> sg[j].S;
	ll res, ans = -1;
	ll ind = -1;
	for(int i = 0; i < n; i++){
		build(i);
		res = a[i] - (*min_element(b, b + n));
		if(res > ans){
			ans = res;
			ind = i;
		}
	}
	cout << ans << '\n';
	for(int i = 0; i < m; i++){
		if((ind+1 < sg[i].F) or (sg[i].S < ind +1)) an.pb(i + 1);
	}
	cout << an.size() << '\n';
	for(auto x : an) cout << x << " ";
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