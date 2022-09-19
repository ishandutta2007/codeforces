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
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

ll a[MAXN][MAXN], dis[MAXN][MAXN];
queue<pll> q;



int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	pll side_adj[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	
	for(int i = 0; i < MAXN; i++) fill(dis[i], dis[i] + MAXN, INF);
	for(int i = 0; i < MAXN; i++) fill(a[i], a[i] + MAXN, -1);
	
	ll n, m;
	cin >> n >> m;
	char c;
	ll x, y, nx, ny;
	for(int i = 1; i <= n;i++){
		for(int j = 1; j <= m; j++){
			cin >> c;
			if(c == 'E'){
				q.push({i, j});
				dis[i][j] = 0;
			} else if(c == 'S'){
				x = i;
				y = j;
				a[i][j] = 0;
			} else if(c != 'T'){
				a[i][j] = (c - '0');
			}
		}
	}
	
	while(q.size()){	
		for(auto move : side_adj){
			nx = move.F + q.front().F;
			ny = move.S + q.front().S;
			if((dis[nx][ny] == INF) and (a[nx][ny] != -1)){
				dis[nx][ny] = dis[q.front().F][q.front().S] + 1;
				q.push({nx, ny});
			}
		}
		q.pop();
	}
	ll ans = 1;
	ll d = dis[x][y];
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if( dis[i][j] <= d){
				ans += a[i][j];
			}
		}
	}
	cout << ans << '\n';
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