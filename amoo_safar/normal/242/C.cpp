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

const ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 1e5 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

const pll corner_adj[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};


ll dis[MAXN];
map<pll, ll> mp;
queue<ll> q;
queue<pll> qp;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(dis, 31, sizeof dis);
	
	ll x0, y0, x1, y1;
	cin >> x0 >> y0 >> x1 >> y1;
	ll n;
	cin >> n;
	ll r, a, b, po = 1;
	for(int i = 0; i < n; i++){
		cin >> r >> a >> b;
		for(ll j = a; j <= b; j++){
			mp[{r, j}] = po;
			po++;
		}
	}
	
	debug("c1");
	ll st = mp[{x0, y0}];
	ll end = mp[{x1, y1}];
	
	debug(st);
		
	dis[st] = 0;
	q.push(st);
	qp.push({x0, y0});
	
	ll x, y, nx, ny, fr, ind;
	while(q.size()){
		fr = q.front();
		x = qp.front().F;
		y = qp.front().S;
		q.pop();
		qp.pop();
		
		for(auto del : corner_adj){
			nx = x + del.F;
			ny = y + del.S;
			if(mp.count({nx, ny})){
				ind = mp[{nx, ny}];
				if(dis[ind] == INF){
					dis[ind] = dis[fr] + 1;
					q.push(ind);
					qp.push({nx, ny});
				}
			}
		}
	}
	
	
	cout << (dis[end] == INF ? -1 : dis[end]) << '\n';
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