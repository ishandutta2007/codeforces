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
const ll MAXN = (ll) 1e3 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

ll dis[MAXN][MAXN], t[MAXN], c[MAXN], n, m;

vector<pll> G[MAXN];
vector<pll> H[MAXN];
set<pll> pq;

void dog_style(ll sc){
	dis[sc][sc] = 0;
	pq.clear();
	pq.insert({0, sc});
	ll fr, d;
	while(pq.size()){
		fr = (*pq.begin()).S;
		d = (*pq.begin()).F;
		pq.erase(pq.begin());
		for(auto ed : G[fr]){
			if(dis[sc][ed.F] > d + ed.S){
				pq.erase({dis[sc][ed.F], ed.F});
				dis[sc][ed.F] = d + ed.S;
				pq.insert({dis[sc][ed.F], ed.F});
			}
		}
	}
	return ;
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(dis, 31, sizeof dis);
	
	ll st, en;
	cin >> n >> m >> st >> en;
	ll u, v, w;
	for(int i = 1; i <= m; i++){
		cin >> u >> v >> w;
		G[u].pb({v, w});
		G[v].pb({u, w});
	}
	for(int i = 1; i <= n; i++) cin >> t[i] >> c[i];
	for(int i = 1; i <= n; i++) dog_style(i);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(dis[i][j] <= t[i]){
				H[i].pb({j, c[i]});
			}
		}
	}
	memset(dis[st], 31, sizeof dis[st]);
	ll sc = st;
	dis[sc][sc] = 0;
	pq.clear();
	pq.insert({0, sc});
	ll fr, d;
	while(pq.size()){
		fr = (*pq.begin()).S;
		d = (*pq.begin()).F;
		pq.erase(pq.begin());
		for(auto ed : H[fr]){
			if(dis[sc][ed.F] > d + ed.S){
				pq.erase({dis[sc][ed.F], ed.F});
				dis[sc][ed.F] = d + ed.S;
				pq.insert({dis[sc][ed.F], ed.F});
			}
		}
	}
	cout << (dis[st][en] == INF ? -1 : dis[st][en]);
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