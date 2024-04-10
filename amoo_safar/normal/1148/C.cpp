#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 1e9 + 7;
const ll MAXN = (ll) 3e5 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;
const ll LOG = (ll) 30;

ll a[MAXN], wh[MAXN], n;

vector<pll> ans;

void swa(ll i, ll j){
	swap(a[i], a[j]);
	ans.pb({i, j});
	wh[a[i]] = i;
	wh[a[j]] = j;
}

void fix(ll x){
	if(a[x] == x) return ;
	ll w = wh[x];
	if(2 * abs(w - x) >= n){
		swa(w, x);
		return ;
	}
	if(2 * abs(w - 1) >= n){
		swa(w, 1);
		return ;
	}
	swa(w, n);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n ;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		wh[a[i]] = i;
	}
	for(int i = 2; i <= n - 1; i++){
		fix(i); fix(i); fix(i);
	} 
	if(a[1] != 1) swa(1, n);
	cout << ans.size() << '\n';
	for(auto x : ans) cout << x.F << " " << x.S << '\n';
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