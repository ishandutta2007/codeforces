#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll Mod = 1e9 + 7;
const int Maxn = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;
ll Base = 101;

map<vector<int>, int> mp;
map<int, vector<int>> rev;
vector<int> p, p1, p2, res;
int App[130][130];
int app(int a, int d){
	p1 = rev[a];
	p2 = rev[d];
	res.clear();
	for(auto x : p2) res.pb(p1[x - 1]);
	//for(auto x : res) cerr << x << ' '; cerr << '\n';
	return mp[res];
}

ll in[Maxn];
vector<ll> gd;
int last[130];

int par[130], sz[130];
ll get(ll u){
	if(par[u] == u) return u;
	return par[u] = get(par[u]);
}
void merge(ll u, ll v){
	u = get(u);
	v = get(v);
	if(u == v) return ;
	par[u] = v;
	sz[v] += sz[u];
}


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for(int i = 1; i < 6; i++) p.pb(i);
	ll cnt = 1;
	do {
		rev[cnt] = p;
		mp[p] = cnt ++;
	} while(next_permutation(all(p)));
	
	ll n, k;
	cin >> n >> k;
	ll v;
	for(int i = 0; i < n; i++){
		p.clear();
		for(int j = 0;j < k;j++){
			cin >> v;
			p.pb(v);
		}
		for(int j = k + 1; j <= 5; j++) p.pb(j);
		in[i] = mp[p];
		//cerr << in[i] << ' ';
		
	}
	for(int i = 1; i < 121; i++)
	for(int j = 1; j < 121; j++) App[i][j] = app(i, j);
	//cerr << '\n';
	ll ans = 0;
	ll la;
	memset(last, -1, sizeof last);
		
	for(int k = n - 1; k >= 0; k--){
		
		iota(par, par + 130, 0);
		fill(sz, sz + 130, 1);
		
		
		last[in[k]] = k;
		gd.clear();
		for(int i = 1; i < 121; i++){
			if(last[i] != -1) gd.pb(last[i]);
		}
		gd.pb(n);
		sort(all(gd));
		//la = i - 1;
		int m = gd.size();
		//cerr << "m " << m<< '\n';
		for(int i = 0; i < m - 1; i++){
			ll nx = App[1][in[gd[i]] ];
			//cerr << "!! " << in[gd[i]] << '\n';
			if(get(nx) != get(1)){
			for(int j = 1; j <= 120; j++){
				//cerr << "?? " << j << " " << app(j, in[gd[i]]) << '\n'; 
				merge(j, App[j][ in[gd[i]]] );
			}
			}
			//cerr << "@@ " << sz[get(1)] << '\n';
			ans += (gd[i + 1] - gd[i]) * sz[get(1)];
			//la = l;
			//cerr << '\n';
		}
		//cerr << '\n';
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