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
const ld EPS = (ld) 1e-8;

ll dp[MAXN][210];
multiset<pll> ms;
vector<pll> ss[MAXN], tt[MAXN];
multiset<pll>::iterator it;
pll mn;

void rem(pll x){
	it = ms.find({-x.F, -x.S});
	if(it != ms.end()) ms.erase(it);
}
void add(pll x){ ms.insert({-x.F, -x.S}); }

pll get_max(){
	if(ms.size() == 0) return {0, -1};
	mn = *ms.begin();
	return {-mn.F, -mn.S};
}

pll nx[MAXN];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m, k;
	cin >> n >> m >> k;
	ll s, t, d, w;
	for(int i = 0; i < k;i++){
		cin >> s >> t >> d >> w;
		ss[s].pb({w, d + 1});
		tt[t].pb({w, d + 1});
	}
	pll mx;
	for(int i = 1; i <= n; i++){
		for(auto x : ss[i]) add(x);
		mx = get_max();
		if(mx.S == -1) mx.S = i + 1;
		nx[i] = mx;
		for(auto x : tt[i]) rem(x);
	}
	nx[0] = {0, 1};
	memset(dp, 31, sizeof dp);
	dp[0][0] = 0;
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
			dp[nx[i].S][j] = min(dp[nx[i].S][j], dp[i][j] + nx[i].F);
		}
	}
	cout << *min_element(dp[n + 1], dp[n + 1] + m + 1);
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