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
typedef pair<int, int> pll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 1e9 + 7;
const ll MAXN = (ll) 5e2 + 6;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

ll mul(ll a, ll b){
	a%=MOD;
	b%=MOD;
	return (a * b) % MOD;
}

ll solve(ll x){
	ll ev = 0, od = 0;
	ll cnt = 1, s = 0 ;
	ll ad, nw = 1;
	while(s <= x){
		ad = min(cnt, x - s);
		if(nw == 0) od += ad;
		else ev += ad;
		nw = 1 - nw;
		s += cnt;
		cnt *= 2;
	}
	return mul(ev,ev) + mul(od, od + 1);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll l, r;
	cin >> l >> r;
	ll ans = solve(r) - solve(l - 1);
	cout << ((ans % MOD) + MOD) %MOD;
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