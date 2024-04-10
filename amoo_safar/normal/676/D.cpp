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
const ll MAXN = (ll) 1e3 + 10;
const ll INF = (ll) 1e15;
const ld EPS = (ld) 1e-8;

ll dp[MAXN][MAXN][4], a[MAXN][MAXN][4], mark[MAXN][MAXN][4];
map<char, ll> mask;
queue< pair<pll, ll> > q;


ll nex(ll v){
	return (2ll * v + min(1ll, v & 8ll)) % 16ll;
}

ll shift(ll v, ll t){
	for(int i = 0; i < t; i++) v = nex(v);
	return v;
}

ll up(ll v) {
	return min(1ll, v & 1ll);
}
ll right(ll v){
	return min(1ll, v & 2ll);
}
ll down(ll v){
	return min(1ll, v & 4ll);
}
ll left(ll v){
	return min(1ll, v & 8ll);
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	mask['+'] = 15;
	mask['-'] = 10;
	mask['|'] = 5;
	mask['^'] = 1;
	mask['v'] = 4;
	mask['>'] = 2;
	mask['<'] = 8;
	mask['L'] = 7;
	mask['R'] = 13;
	mask['U'] = 14;
	mask['D'] = 11;
	mask['*'] = 0;
	for(int i = 0; i < MAXN; i++){
		for(int j = 0; j < MAXN; j++){
			for(int k = 0; k < 4; k++) dp[i][j][k] = INF;
		}
	}
	
	ll n, m;
	cin >> n >> m;
	char c;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> c;
			a[i][j][0] = mask[c];
			a[i][j][1] = shift(a[i][j][0], 1);
			a[i][j][2] = shift(a[i][j][0], 2);
			a[i][j][3] = shift(a[i][j][0], 3);
		}
	}
	
	ll x, y, x2, y2;
	cin >> x >> y;
	cin >> x2 >> y2;
	q.push({{x, y}, 0});
	mark[x][y][0] = 1;
	dp[x][y][0] = 0;
	pair< pll, ll> po;
	ll f, s, t, nt;
	
	ll now, bef;
	ll mo;
	debug(nex(8));
	debug(a[1][1][1]);
	
	while( q.size() > 0 ){
		po = q.front();
		f = po.F.F;
		s = po.F.S;
		t = po.S;
		nt = (t + 1) % 4;
		mo = dp[f][s][t];
		if(!mark[f][s][nt]){
			q.push({{f, s}, nt});
			mark[f][s][nt] = 1;
			dp[f][s][nt] = mo + 1;
		}
		//debug(f);
		//debug(s);
		//debug(t);
		if((!mark[f + 1][s][t]) and (down(a[f][s][t])) and (up(a[f + 1][s][t]))){
			q.push({{f + 1, s}, t});
			mark[f + 1][s][t] = 1;
			dp[f + 1][s][t] = mo + 1;
		}
		if((!mark[f - 1][s][t]) and (down(a[f - 1][s][t])) and (up(a[f][s][t]))){
			q.push({{f - 1, s}, t});
			mark[f - 1][s][t] = 1;
			dp[f - 1][s][t] = mo + 1;
		}
		if((!mark[f][s + 1][t]) and (right(a[f][s][t])) and (left(a[f][s + 1][t]))){
			q.push({{f, s + 1}, t});
			mark[f][s + 1][t] = 1;
			dp[f][s + 1][t] = mo + 1;
		}
		if((!mark[f][s - 1][t]) and (right(a[f][s - 1][t])) and (left(a[f][s][t]))){
			q.push({{f, s - 1}, t});
			mark[f][s - 1][t] = 1;
			dp[f][s - 1][t] = mo + 1;
		}
		
		q.pop();
	}
	
	
	ll ans = INF;
	for(int i = 0; i < 4; i++) ans = min(ans , dp[x2][y2][i]);
	cout << (ans == INF ? -1 : ans) << '\n';
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