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
const ll MAXN = (ll) 1e2 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

ll a[MAXN];
ll calc(ll a, ll b){
	if(a == b) return 0;
	if(a == 1) return (b == 2 ? -1 : 1);
	if(a == 2) return (b == 3 ? -1 : 1);
	return (b == 1 ? -1 : 1);
}

ll f[5][5], s[5][5];
vector<ll> res;
map<pll, ll> mp;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, k;
	ll a, b;
	cin >> k >> a >> b;
	for(int i= 1;i<=3;i++) for(int j =1;j<=3;j++) cin >> f[i][j];
	for(int i= 1;i<=3;i++) for(int j =1;j<=3;j++) cin >> s[i][j];
	
	ll p1 = 0, p2 = 0;
	ll t, y;
	for(int i = 1;i <= 81;i++){
		if(mp[{a, b}] != 0){
			t = i - mp[{a, b}];
			y = i - t - 1;
			break;
		}
		res.pb(calc(a,b));
		//debug(a); debug(b);
		//if(res.back() == 1) p1 ++;
		//if(res.back() == -1) p2 ++;
		mp[{a, b}] = i;
		ll aa = a;
		ll bb = b;
		a = f[aa][bb]; b = s[aa][bb];
	}
	debug(t); debug(y);
	p1 = p2 = 0;
	for(int i = 0; i < min(k, y); i++){
		if(res[i] == 1) p1 ++;
		if(res[i] == -1) p2 ++;
	}
	if(k <= y){
		cout << p1 << " " << p2;
		return 0;
	}
	ll z = (k - y) / t;
	for(int i = y; i<res.size(); i++){
		if(res[i] == 1) p1 += z;
		if(res[i] == -1) p2 += z;
	}
	ll r = (k - y) % t;
	z = 1;
	for(int i = y; i<y + r; i++){
		if(res[i] == 1) p1 += z;
		if(res[i] == -1) p2 += z;
	}
	cout << p1<< " " << p2;
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