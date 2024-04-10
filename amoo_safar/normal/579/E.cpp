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
const ll INF = (ll) 1e10;
const ld EPS = (ld) 1e-8;

ll n, a[MAXN];
ld b[MAXN];

void update(ld x){
	for(int i = 0; i < n; i++) b[i] = a[i] - x;
}

void change(){
	for(int i = 0; i < n; i++) b[i] = -b[i];
}

ld weakness(){
    ld ans = 0.0;
    ld su = 0.0;
    for(int i = 0; i < n; i++){
        su += b[i];
        su = max((ld) 0.0, su);
        ans = max(ans, su);
    }
    return ans;
}

ld weak(ld x){
	ld ans1, ans2;
	
	update(x);
	ans1 = weakness();
	change();
	ans2 = weakness();
	
	return max(ans1, ans2);
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cout.precision(12);
	
	cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
	ld up = INF;
	ld dw = -INF;
	ld mid1, mid2;
	for(int i = 0; i < 200; i++){
		mid1 = (2 * dw + up) / 3;
		mid2 = (dw + 2 * up) / 3;
		if(weak(mid1) > weak(mid2)) dw = mid1;
		else up = mid2;
	}
	cout << fixed << weak(up) << endl;
	//cout << fixed << up;
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