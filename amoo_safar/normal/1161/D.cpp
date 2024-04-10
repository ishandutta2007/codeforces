#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) //cerr << #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 4e3 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

vector<pll> G[MAXN];
ll type[MAXN];
ll mk[MAXN];
bool fl;

void DFS(ll u, ll t){
	//debug(u);debug(t);
	debug(u);
	//if(type[u] == t) return ;
	if(type[u] == -1) type[u] = t;
	if(type[u] != t) {
		fl = false;
		//debug(u);
		return ;
	}
	if(mk[u] == 1) return ;
	mk[u] = 1;
	//ll adj;
	for(auto e : G[u]){
		DFS(e.F, t ^ e.S);
		debug(e.F);
		debug(u);
		debug(e.S);
		debug('\n');
	}
	return ;
}


ll pw(ll y){
	ll ans = 1;
	for(int i = 0; i < y; i++) ans = (ans + ans) % MOD;
	return ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	str s;
	cin >> s;
	ll n = s.size();
	ll ans = 0;
	for(int len = 1; len < n; len ++){
		// data reset
		memset(mk, 0, sizeof mk);
		memset(type, -1, sizeof type);
		fl = true;
		for(int i = 0; i < n + n; i++) G[i].clear();
		////
		for(int i = 0; i < n; i++){
			G[i].pb({n - 1 - i, 0});
		}
		///
		for(int i = 0; i < len; i++){
			G[i + n].pb({len - 1 - i + n, 0});
		}
		////
		for(int i = 0; i < n; i++){
			if(s[n - 1 - i] == '?') continue;
			if(s[n - 1 - i] == '1'){
				G[i].pb({i + n, 1});
				G[i + n].pb({i, 1});
			}
			if(s[n - 1 - i] == '0'){
				G[i].pb({i + n, 0});
				G[i + n].pb({i, 0});
			}
		}
		////
		
		bool fg = true;
		for(int i = n + len; i < n + n; i++) type[i] = 0;
		type[n - 1] = 1;
		debug("\n");
		fl = true;
		DFS(n - 1, 1);
		
		//for(int i = 0; i<n+n;i++) cerr << type[i] << " ";
		//cerr << '\n';
		if(fl == false) fg = false;
		debug(fg);
		type[len - 1 + n] = 1;
		debug("\n");
		fl = true;
		DFS(len - 1 + n, 1);
		
		//for(int i = 0; i<n+n;i++) cerr << type[i] << " ";
		//cerr << '\n';
		if(fl == false) fg = false;
		
		
		for(int i = n + len; i < n + n; i++){
			fl = true;
			DFS(i,0);
			if(fl == false) fg = false;
		}
		debug(fg);
		///
		ll com = 0;
		for(int i = 0; i < n+ n; i++){
			if(mk[i] == 0){
				com ++;
				fl = true;
				DFS(i, 0);
				if(fl == false) fg = false;
			}
		}
		
		//for(int i = 0; i<n+n;i++) cerr << type[i] << " ";
		///cerr << '\n';
		debug(len);
		//debug(com);
		debug(fg);
		if(fg) ans += pw(com);
		ans %= MOD;
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