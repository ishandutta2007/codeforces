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
const ll MAXN = (ll) 2e5 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

ll par[MAXN], cap[MAXN], in[MAXN];


ll get_par(ll node){
	if(par[node] == node) return node;
	par[node] = get_par(par[node]);
	return par[node];
}

void merge(ll u, ll v){
	u = get_par(u);
	v = get_par(v);
	if(u == v) return ;
	par[u] = v;
	return ;
}

void add(ll ind, ll val){
	if(in[ind] + val <= cap[ind]){
		in[ind] += val;
		return ;
	} else {
		ll nex = cap[ind] - in[ind];
		in[ind] += nex;
		val -= nex;
		merge(ind, ind + 1);
		add(par[ind], val);
	}
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for(int i = 0; i < MAXN; i++) par[i] = i;
	ll n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> cap[i];
	cap[n] = INF;
	
	ll q, t, ind, val;
	cin >> q;
	for(int i = 0; i < q; i++){
		cin >> t;
		if(t == 1){
			cin >> ind >> val;
			ind --;
			add(ind, val);
		} else {
			cin >> ind;
			ind --;
			cout << in[ind] << '\n';
		}
	}
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