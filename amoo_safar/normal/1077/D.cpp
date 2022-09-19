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
const ll MAXN = (ll) 2e5 + 10;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

map<ll, ll> m;
vector<ll> ans;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n, k;
	cin >> n >> k;
	ll v;
	for(int i = 0;i<n;i++){
		cin >> v;
		m[v]++;
	}
	ll up = n;
	ll dw = 1;
	ll mid;
	ll cnt;
	while(dw + 1 < up){
		//ans.clear();
		cnt = 0;
		mid = (dw + up) / 2;
		for(auto x : m){
			cnt = cnt + (x.S / mid);
		}
		if(cnt >= k) dw = mid;
		else up = mid;
	}
	
	for(auto x : m){
		for(int i = 0; i < x.S / dw;i++)ans.pb(x.F);
	}
	for(int i = 0;i<k;i++)cout << ans[i] << " ";
	
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