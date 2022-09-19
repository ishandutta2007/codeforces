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
const ll MAXN = (ll) 1e6 + 10;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

ll par[MAXN], sz[MAXN], a[MAXN], b[MAXN];

bool CMP(ll i, ll j){
	if(a[i] == a[j]) return i > j;
	return a[i] > a[j];
}

ll get_par(ll node){
	ll x = par[node];
	if(x == node) return node;
	par[node] = get_par(x);
	return par[node];
}

void merge(ll a, ll b){
	ll x = get_par(a);
	ll y = get_par(b);
	if(x == y) return ;
	par[x] = y;
	sz[y] += sz[x];
}

vector<ll> g[MAXN], ch;
pll ed[MAXN];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(int i = 0; i < MAXN; i++) par[i] = i;
	ll n, m, u, v;
	//cin >> n;
	scanf("%lld", &n);
	m = n - 1;
	for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
	for(int i = 0; i < n; i++) b[i] = i;
	fill(sz, sz + n, 1);
	sort(b, b + n, CMP);
	
	for(int i = 0; i < m; i++){
		scanf("%lld%lld", &u, &v);
		//cin >> u >> v;
		ed[i] = {u, v};
		u--;v--;
		if(a[u] > a[v]) swap(u, v);
		if(a[u] == a[v]){
			if(u > v) swap(u, v);
		}
		g[u].pb(v);
	}
	ll ans = 0;
	ll node, s, ba;
	
	for(int i = 0; i < n; i++){
		ch.clear();
		node = b[i];
		//debug(node);
		//debug(ans);
		for(auto adj : g[node]){
			ch.pb(get_par(adj));
		}
		if(ch.size() == 0) continue;
		sort(all(ch));
		ch.resize( unique(all(ch)) - ch.begin());
		s = 0;
		for(auto x : ch){
			s += sz[x];
		}
		ans += (a[node] * s);
		for(auto x : ch){
			s -= sz[x];
			ans += (a[node] * s * sz[x]);
			
		}
		ba = ch.back();
		ch.pop_back();
		for(auto x : ch){
			merge(x, ba);
		}
		merge(node, ba);
		//debug(ans);
	}
	ll ans1 = ans;
	//debug(ans1);
	//cout << fixed << setprecision(12) << 2 * ans / 1.0 / (n * (n - 1));
	for(int i = 0; i < MAXN; i++) g[i].clear();
	for(int i = 0; i < MAXN; i++) par[i] = i;
	m = n - 1;
	for(int i = 0; i < n; i++) a[i] = -a[i];
	for(int i = 0; i < n; i++) b[i] = i;
	fill(sz, sz + n, 1);
	sort(b, b + n, CMP);
	
	for(int i = 0; i < m; i++){
		u = ed[i].F;
		v = ed[i].S;
		u--;v--;
		if(a[u] > a[v]) swap(u, v);
		if(a[u] == a[v]){
			if(u > v) swap(u, v);
		}
		g[u].pb(v);
	}
	ans = 0;
	
	for(int i = 0; i < n; i++){
		ch.clear();
		node = b[i];
		//debug(node);
		//debug(ans);
		for(auto adj : g[node]){
			ch.pb(get_par(adj));
		}
		if(ch.size() == 0) continue;
		sort(all(ch));
		ch.resize( unique(all(ch)) - ch.begin());
		s = 0;
		for(auto x : ch){
			s += sz[x];
		}
		ans += (a[node] * s);
		for(auto x : ch){
			s -= sz[x];
			ans += (a[node] * s * sz[x]);
			
		}
		ba = ch.back();
		ch.pop_back();
		for(auto x : ch){
			merge(x, ba);
		}
		merge(node, ba);
		//debug(ans);
	}
	ans = -ans;
	//debug(ans);
	printf("%lld", ans - ans1);
	//cout << ans - ans1;
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