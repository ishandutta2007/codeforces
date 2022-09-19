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

ll a[MAXN], b[MAXN], n;

bool CMP1(ll i, ll j){
	return b[i] < b[j];
}

bool CMP2(ll i, ll j){
	return b[i] > b[j];
}
ll ind[MAXN];
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	ll cnt = 0;
	for(int i = 1; i<= n; i++){
		cin >> a[i] >> b[i];
		if(b[i] > a[i]) cnt++;
		ind[i] = i;
	}
	if(n - cnt > cnt){
		cout << n - cnt << '\n';
		sort(ind + 1, ind + n + 1, CMP1);
		for(int i = 1; i<= n; i++){
			ll ii = ind[i];
			if(a[ii] > b[ii]) cout << ii << " ";
		}
		
	} else {
		cout << cnt << '\n';
		sort(ind + 1, ind + n + 1, CMP2);
		for(int i = 1; i<= n; i++){
			ll ii = ind[i];
			if(a[ii] < b[ii]) cout << ii << " ";
		}
		
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