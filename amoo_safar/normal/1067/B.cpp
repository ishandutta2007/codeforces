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
const ll MAXN = (ll) 1e5 + 10;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

set<ll> g[MAXN];

ll vis[MAXN];

void rem(ll node){
	for(auto adj : g[node]){
		g[adj].erase(node);
	}
	g[node].clear();
}

queue<ll> bf, bf2;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n, k, u, v;
	cin >> n >> k;
	for(int i = 0; i < n-1; i++){
		cin >> u >> v;
		u--;
		v--;
		g[u].insert(v);
		g[v].insert(u);
	}
	for(int i = 0; i < n; i++){
		if(g[i].size() == 1)bf.push(i);
	}
	ll no;
	ll kk = 0;
	while(bf.size() != 0){
		//debug(bf.front());
		fill(vis, vis + MAXN, 0);
		while(bf.size() != 0){
			no = bf.front();
			vis[*g[no].begin()] ++;
			rem(no);
			bf.pop();
		}
		for(int i = 0;i < n; i++){
			if(vis[i] != 0){
				if(g[i].size() == 0 and vis[i] < 3) return cout << "No", 0;
				if(g[i].size() == 0) continue;
				//debug(i);
				if((g[i].size() != 1) or (vis[i] < 3)) return cout << "No", 0;
			}
		}
		
		for(int i = 0;i < n; i++){
			if(g[i].size() == 1){
				bf.push(i);
			}
		}
		kk++;
	}
	//debug(kk);
	if(kk == k) cout << "Yes";
	else cout << "No";
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