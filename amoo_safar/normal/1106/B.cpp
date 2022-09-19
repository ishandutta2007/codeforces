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
const ll MAXN = (ll) 1e5 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-12;

ll ind[MAXN], c[MAXN], a[MAXN];

bool CMP(ll i, ll j){
	if(c[i] == c[j]) return i < j;
	return c[i] < c[j];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m;
    cin >> n >> m; 
    for(int i = 0; i< n; i++){
		cin >> a[i];
		ind[i] = i;
	}
	for(int i = 0;i<n;i++) cin >> c[i];
	sort(ind, ind + n, CMP);
	ll p0= 0;
	ll x, ans, s, t, cnt, j;
	for(int i = 0; i< m; i++){
		cin >> t >> cnt;
		t--;
		ans = 0;
		x = min(cnt, a[t]);
		cnt -=x; a[t] -= x;
		ans += (x * c[t]);
		if(cnt == 0) {
			cout << ans << '\n';
			continue;
		}
		while(cnt > 0){
			if(p0 == n) break;
			j = ind[p0];
			x = min(cnt, a[j]);
			cnt -= x; a[j] -= x;
			ans += (c[j] * x);
			if(a[j] == 0) p0++;
		}
		if(cnt > 0) ans = 0;
		cout << ans << '\n';
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