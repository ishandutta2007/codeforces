#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) //cerr << #x << " : " << x << '\n'; 
using namespace std;

typedef int ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 15;
const ll N = 1e5 + 100;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

int dp[(1 << 14)][MAXN][MAXN];
int p[(1 << 14)][MAXN][MAXN];
int dp2[(1 << 14)];
pair<int, pll> p2[(1 << 14)];
int G[MAXN][MAXN], OK[MAXN];

ll lb(ll x){
	for(int i = 0; i< 14; i++) if (x & (1ll << i)) return i;
}
vector<ll> bt[15], good;


vector<pll> ans;

void HAMP(ll i, ll j, ll mk){
	//debug(i);
	//debug(j);
	//debug(mk);
	while(i != j){
		//if(dp[mk][i][j] == 0) return ;
		//debug(j);
		//debug(mk);
		ans.pb({j, p[mk][i][j]});
		int mk2 = mk;
		mk = mk ^ (1 << j);
		j = p[mk2][i][j];
		
	}
	return ;
}

int main(){
	int n, m;
	cin >> n >> m;
	int u, v;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		u--; v--;
		G[u][v] = G[v][u] = 1;
	}
	
	for(int i = 0; i < (1 << n); i++) bt[__builtin_popcount(i)].pb(i);
	for(int i = 0; i < n; i++) dp[1 << i][i][i] = 1;
	
	for(int mk = 1; mk < (1 << n); mk ++){	
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(dp[mk][i][j] == 0) continue;
				for(int nx = 0; nx < n; nx ++){
					if(mk & (1ll << nx)) continue;
					if(G[j][nx]){
						dp[mk | (1ll << nx)][i][nx] = 1;
						p[mk | (1ll << nx)][i][nx] = j;
					}
				}
			}
		}
	}
	memset(dp2, 31, sizeof dp2);
	
	for(int mk = 1; mk < (1 << n); mk ++){
		if(__builtin_popcount(mk) < 3) continue;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if((dp[mk][i][j] == 1) and (G[i][j] == 1)){
					dp2[mk] = __builtin_popcount(mk);
					p2[mk] = {mk, {i, j}};
					//debug(mk);
				}
			}
		}
	}
	
	for(int mk = 1; mk < (1 << n) - 1; mk ++){
		int pc = __builtin_popcount(mk);
		if(pc < 3) continue;
		memset(OK, 0, sizeof OK);
		for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if((mk & (1 << j)) && (G[i][j] == 1)) OK[i] ++;
		
		good.clear();
		for(int cc = 1; cc <= min(pc - 1, n - pc); cc++){
			for(auto mk2 : bt[cc]){
				if(mk & mk2) continue;
				good.pb(mk2);
			}
		}
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(min(OK[i], OK[j]) <= 0) continue;
				if(i == j and OK[i] == 1) continue;
				if( (mk & (1 << i)) || (mk & (1 << j))) continue;
		
				for(auto mk2 : good){
					if(dp[mk2][i][j] == 0) continue;
					if(mk & mk2) continue;
					if(dp2[mk | mk2] > dp2[mk] + __builtin_popcount(mk2) + 1 ){
						dp2[mk | mk2] = dp2[mk] + __builtin_popcount(mk2) + 1;
						p2[mk | mk2] = {mk, {i, j}};
					}
				}
			}
		}
	}
	
	cout << dp2[(1 << n) - 1] << '\n'; 
	ll mask = (1 << n) - 1;
	debug("S");
	debug(p2[mask].F);
	while(p2[mask].F != mask){
		debug(mask);
		
		int add = mask ^ p2[mask].F;
		int nx = p2[mask].F;
		debug(mask)
		HAMP(p2[mask].S.F, p2[mask].S.S, add);
		int i = p2[mask].S.F, j = p2[mask].S.S;
		for(int k = 0; k < n; k++) if((nx & (1 << k)) and (G[i][k] == 1)){
			ans.pb({i, k});
			break;
		}
		for(int k = n - 1; k >= 0; k--) if((nx & (1 << k)) and (G[j][k] == 1)){
			ans.pb({j, k});
			break;
		}
		mask = nx;
		//debug(mask);
	}
	cerr << "mask : " << mask << '\n';
	ans.pb(p2[mask].S);
	
	HAMP(p2[mask].S.F, p2[mask].S.S, p2[mask].F);
	for(auto x : ans) cout << x.F + 1 << " " << x.S + 1 << '\n';
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