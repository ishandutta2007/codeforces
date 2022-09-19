#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;

typedef int ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 2e5 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

ll n, m;
map<str, ll> mp;
set<ll> st;
ll A[50][50];
ll dp1[1ll << 20], dp2[1ll << 20], p2[20];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	ll t, p = 0, ans = 1;
	if(m == 1) return cout << 1, 0;
	str s;
	for(int i = 0; i < n; i++){
		cin >> t;
		if(t == 1){
			for(auto x : st)
				for(auto y : st){
					A[x][y] = 1;
					A[y][x] = 1;
				}
			st.clear();
		} else {
			cin >> s;
			if(mp.count(s) == 0){
				mp[s] = p;
				p++;
			}
			st.insert(mp[s]);
			//debug(cnt[mp[s]]);
		}
	}
	for(auto x : st)
		for(auto y : st){
			A[x][y] = 1;
			A[y][x] = 1;
		}
	st.clear();
	
	ll h1 = m / 2;
	ll h2 = m - h1;
	ll fl;
	
	for(int i = 0; i < 20; i++) p2[i] = (1ll << i);
	ll pw = (1ll << h1) - 1;
	
	for(int i = 1; i <= (1ll << h1); i++){
		fl = 1;
		for(int j = 0; j < h1; j++) for(int k = j + 1; k < h1; k++){
			if((i & p2[j]) && (i & p2[k]) && A[j][k]) {
				fl = 0;
				break;
			}
		}
		if(fl) dp1[i] = __builtin_popcountll(i);
		for(int j = 0; j < h1;j++) dp1[i] = max(dp1[i], dp1[i & (pw - p2[j])]);
		ans = max(ans, dp2[i]);
	}
	
	pw = (1ll << h2) - 1;
	
	for(int i = 1; i <= (1ll << h2); i++){
		fl = 1;
		for(int j = 0; j < h2; j++) for(int k = j + 1; k < h2; k++){
			if((i & p2[j]) && (i & p2[k]) && A[h1 + j][h1 + k]) {
				fl = 0;
				break;
			}
		}
		if(fl) dp2[i] = __builtin_popcountll(i);
		for(int j = 0; j < h2;j++) dp2[i] = max(dp2[i], dp2[i & (pw - p2[j])]);
		ans = max(ans, dp2[i]);
	}
	ll cpw = pw;
	for(int i = 1; i < (1ll << h1); i++){
		pw = 1ll << h2;
		pw --;
		for(int j = 0; j < h1; j++) for(int k = h1; k < m; k++){
			if((i & p2[j]) && (A[j][k])) pw &= (cpw - p2[k - h1]);
		}
		ans = max(ans,dp1[i] + dp2[pw]);
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