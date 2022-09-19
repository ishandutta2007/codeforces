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
const ll MAXN = (ll) 1e3 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

pll side_adj[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
ll n, m, p;
vector<pll> C[12], fut;
char t[MAXN][MAXN];
ll s[20];

void move(ll pl){
	ll nx, ny;
	for(int i = 0; i < s[pl]; i++){
		if(C[pl].size() == 0) return ;
		fut.clear();
		for(auto cell : C[pl]){
			for(auto del : side_adj){
				nx = cell.F + del.F;
				ny = cell.S + del.S;
				if(t[nx][ny] == '.'){
					t[nx][ny] = ((char)(pl + '1'));
					fut.pb({nx, ny});
				}
			}
		}
		C[pl].clear();
		for(auto x : fut) C[pl].pb(x);
	}
	return ;
}

ll cn[20];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//for(int i = 0 ; i< MAXN; i++) fill(t[i], t[i] + MAXN, '*');
	cin >> n >> m >> p;
	for(int i = 0; i < p; i++) cin >> s[i];
	str st;
	for(int i = 1; i <= n; i++){
		cin >> st;
		for(int j = 1; j <= m; j++){
			//cin >> t[i][j];
			t[i][j] = st[j - 1];
			if( '0' <= t[i][j] and t[i][j] <= '9'){
				C[t[i][j] - '1'].pb({i, j});
			}
		}
	}
	for(int i = 0; i< p*n*m; i++){
		move(i % p);
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if( '1' <= t[i][j] and t[i][j] <= '9') cn[t[i][j] - '1'] ++;
		}
	}
	for(int i = 0; i < p; i++) cout << cn[i] << " ";
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