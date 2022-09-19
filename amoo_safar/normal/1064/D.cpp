#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 2e3 + 10;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

str ma[MAXN];

ll dis[MAXN][MAXN];
ll col_add[MAXN][MAXN];

deque<pll> bf;

ll n, m;

ll i2;
void add_col(ll i, ll j, ll d){
	if(col_add[i][j] == 1) return ;
	col_add[i][j] = 1;
	if(ma[i][j] == '*') return;
	if(dis[i][j] == -1){
		bf.push_front( mp(i, j));
	}
	dis[i][j] = d;
	if(i < n - 1){
		add_col(i + 1, j, d);
	}
	if(i > 0){
		add_col(i - 1, j, d);	
	}

	/*
	i2 = i - 1;
	while(i2 >= 0){
		if((ma[i2][j] == '*') or (dis[i2][j] != -1)) break;
		bf.push( mp(i2, j) );
		dis[i2][j] = d;
		i2--;
	}
	i2 = i + 1;
	while(i2 < n){
		if((ma[i2][j] == '*') or (dis[i2][j] != -1)) break;
		bf.push( mp(i2, j) );
		dis[i2][j] = d;
		i2++;
	}*/
}

void add_row(ll i, ll j, ll d){
	if(j > 0){
		if((j > 0) and (ma[i][j-1] == '.') and (dis[i][j-1] == -1)){
			bf.push_back( mp(i, j - 1) );
			dis[i][j-1] = d;
		}
	}
	if(j < m-1){
		if((j < m - 1) and (ma[i][j+1] == '.') and (dis[i][j+1] == -1)){
			bf.push_back( mp(i, j + 1) );
			dis[i][j+1] = d;
		}
	}
}

int main(){
	for(int i = 0;i<MAXN;i++) fill(dis[i],dis[i]+MAXN, -1);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;

	
	ll r, c;
	cin >> r >> c;
	ll x, y;
	cin >> x >> y;
	for(int i = 0; i < n; i++){
		cin >> ma[i];
	}
	
	
	r--;
	c--;
	
	bf.push_front(mp(r, c));
	//debug(bf.max_size);
	dis[r][c] = 0;
	ll ii, jj;
	while(bf.size()> 0){
		ii = (bf.front()).F;
		jj = (bf.front()).S;
		bf.pop_front();
		add_col(ii, jj, dis[ii][jj]);
		add_row(ii, jj, dis[ii][jj] + 1);
		
	}
	/*for(int i = 0;i<n;i++){
		for(int j =0;j<m;j++) cout << dis[i][j] << " ";
		cout << endl;
	}*/
	ll ans = 0;
	ll xx, yy;
	for(int i = 0;i<n;i ++){
		for(int j = 0;j<m;j++){
			if(ma[i][j] == '*') continue;
			if(dis[i][j] == -1) continue;
			if(j < c){
				yy = c - j;
				xx = (dis[i][j] - (c - j)) / 2;
				yy = yy + (dis[i][j] - (c - j)) / 2;
			}
			if(j == c){
				xx = (dis[i][j]) / 2;
				yy = (dis[i][j] ) / 2;
			}
			if(j > c){
				xx = j - c;
				yy = (dis[i][j] - (j - c)) / 2;
				xx = xx + (dis[i][j] - (j - c)) / 2;
			}
			if((xx <= y) and (yy <= x)) {
				ans ++;
				//debug(i);
				//debug(j);
			}
		}
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