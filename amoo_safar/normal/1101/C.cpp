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
const ll MAXN = (ll) 1e5 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

pll Un(pll a, pll b){
	if( (a.S < b.F) or (b.S < a.F)) return {-1, -1};
	return {min(a.F, b.F), max(a.S, b.S)};
}

pll a[MAXN];
ll b[MAXN];
ll c[MAXN];

bool CMP(ll i, ll j){
	return a[i].F < a[j].F;
}

ll MAIN(){
	memset(c, 0, sizeof c);
	ll n;
	cin >> n;
	for(int i = 0;i<n;i++){
		b[i] = i;
		cin >> a[i].F >> a[i].S;
	}
	sort(b, b + n, CMP);
	pll res, seg = a[b[0]];
	ll j, e = 0;
	for(int i = 1; i < n; i++){
		j = b[i];
		res = Un(seg, a[j]);
		if(res.F == -1) break;
		e = i;
		seg = res;
	}
	//debug(e);
	if(e == n - 1) return cout << -1 << '\n', 0;
	for(int i = 0; i <= e; i++) c[b[i]] = 2;
	for(int i = 0; i < n;i++) cout << max(c[i], 1ll) << " ";
	cout << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	while(T--){
		MAIN();
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