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
const ll MAXN = (ll) 3e5 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

ll f = 500000000;
str t;
bool check(ll x){
	if(x >= f) return false;
	cout << "? " << x << " " << 2 * x << endl;
	cin >> t;
	if(t == "y") return true;
	return false;
}

bool final(ll x){
	cout << "? 0 " << x << endl;
	cin >> t;
	if(t == "x") return true;
	return false;
}

void play(){
	str s;
	cin >> s;
	if(s == "end") return ;
	ll la = 0;
	ll t = 1;
	while(check(t)) la = t, t *= 2;
	ll l = la, r = t, mid;
	while(l + 1 < r){
		mid = (l + r) / 2;
		if(check(mid)) l = mid;
		else r = mid;
	}
	la = l;
	if(final(la + la + 1)) cout << "! " << la + la + 1 << endl;
	else cout <<"! " << la + la + 2 << endl;
	play();
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	play();
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