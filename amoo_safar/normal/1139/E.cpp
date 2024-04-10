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
const ll MAXN = (ll) 5e3 + 100;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

ll x[MAXN], y[MAXN], r[MAXN], mark[2 * MAXN], match[2 * MAXN];
vector<ll> g[2 * MAXN];


bool DFS(ll node){
	if( (mark[node] == 1) || (node == -1)) return false;
	
	mark[node] = 1;
	
	for(auto adj : g[node]){
		if( (match[adj] == -1) || ( DFS(match[adj]) ) ){
			match[adj] = node;
			return true;
		}
	}
	return false;
}
ll n;
void add_edge(ll i, ll j){
	g[i].pb(j + MAXN + 1);
	g[j + MAXN + 1].pb(i);
}

ll in[MAXN];
ll p[MAXN], c[MAXN];
vector<ll> q, ans;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	fill(in, in + MAXN, 1);
	memset(match, -1, sizeof match);
	
	ll m;
	cin >> n;
	cin >> m;
	for(int i = 0; i < n; i++) cin >> p[i];
	for(int i = 0; i < n; i++) cin >> c[i];
	for(int i = 0; i < n; i++) c[i] --;
	ll d;
	cin >> d;
	ll st;
	for(int i = 0; i< d;i++){
		cin >> st;
		st --;
		in[st]=0;
		q.pb(st);
	}
	for(int i = 0; i< n;i++){
		if(in[i] == 1){
			q.pb(i);
		}
	}
	ll mex = 0;
	ans.pb(0);
	for(int i = 0; i < n; i++) {
		memset(mark, 0, sizeof mark);
		st = q.back();
		//debug(st);
		q.pop_back();
		add_edge(c[st], p[st]);
		while(mex <= m && DFS(mex + MAXN + 1)) {memset(mark,0,sizeof mark);mex ++;}
		ans.pb(mex);
	}
	ans.pop_back();
	for(int i = 0; i<d;i++) {
		cout << ans.back() << '\n';
		ans.pop_back();
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