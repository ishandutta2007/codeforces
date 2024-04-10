#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
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
const ll MAXN = (ll) 3e5 + 100;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

ll n, k;
ll s = 0;
pll a[MAXN];

multiset<ll> st;

void add(ll x){
	if(st.size() < k - 1){
		st.insert(x);
		s+=x;
		return ;
	}
	if(k == 1) return ;
	ll mn = *st.begin();
	if(mn < x){
		s -= mn;
		st.erase(st.begin());
		s+=x;
		st.insert(x);
	}
	return ;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> a[i].S >> a[i].F;
	}
	sort(a, a + n);
	ll ans = 0;
	for(int i = n - 1; i>= 0; i--){
		ans = max(ans, (s + a[i].S) * a[i].F);
		add(a[i].S);
	}
	cout << ans;
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