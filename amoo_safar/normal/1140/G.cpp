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
const ll N = (ll) 3e5 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;
const ll LOG = (ll) 20;

vector<pll> G[N], T1[N], T2[N];
ll n, ch[N], ind[N], dep[N];

bool CMP(ll i, ll j){
	return ch[i] < ch[j];
}

ll sp[N][LOG];
ll dp[N][LOG][2][2];

void DFS(ll u, ll p){
	ll cnt_adj = T1[u].size();
	ll adj;
	for(int i = 0; i < cnt_adj; i++){
		adj = T1[u][i].F;
		ll w1 = T1[u][i].S;
		ll w2 = T2[u][i].S;
		
		if(adj == p) continue;
		sp[adj][0] = u;
		
		dep[adj] = dep[u] + 1;
		DFS(adj, u);
		
		dp[adj][0][0][0] = min({ ch[adj] + w2 + ch[u], w1 });
		dp[adj][0][0][1] = min({ ch[adj] + w2, w1 + ch[u] });
		dp[adj][0][1][0] = min({ w2 + ch[u], ch[adj] + w1 });
		dp[adj][0][1][1] = min({ w2, ch[adj] + w1 + ch[u] });
	}
}

struct node {
	ll id;
	ll d0;
	ll d1;
};

node lift(node u, ll p){
	node v;
	v.id = sp[u.id][p];
	v.d0 = min({ u.d0 + dp[u.id][p][0][0], u.d1 + dp[u.id][p][1][0]});
	v.d1 = min({ u.d0 + dp[u.id][p][0][1], u.d1 + dp[u.id][p][1][1]});
	return v;
}

node blift(node u, ll h){
	for(int i = 0; i < LOG; i++){
		if(h & (1ll << i)) u = lift(u, i);
	}
	return u;
}

ll dis(node u, node v){
	if( dep[u.id] < dep[v.id] ) swap(u, v);
	u = blift(u, dep[u.id] - dep[v.id]);
	
	if(u.id == v.id){
		return min(u.d0 + v.d0, u.d1 + v.d1);
	}
	for(int i = LOG - 1; i >= 0; i--){
		if(sp[u.id][i] != sp[v.id][i]){
			u = lift(u, i); v = lift(v, i);
		}
	}
	u = lift(u, 0);
	v = lift(v, 0);
	return min(u.d0 + v.d0, u.d1 + v.d1);
}

set<pll> st;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for(int i = 0; i < N; i++) ind[i] = i;
	memset(dp, 31, sizeof dp);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> ch[i];
	ll a, b, w1, w2;
	for(int i = 1; i < n; i++){
		cin >> a >> b >> w1 >> w2;
		
		T1[a].pb({b, w1});
		T1[b].pb({a, w1});
		
		T2[a].pb({b, w2});
		T2[b].pb({a, w2});
	}
	
	for(int i = 1; i <= n; i++) st.insert({ch[i], i});
	while(st.size()){
		ll fr = st.begin() -> S;
		st.erase(st.begin());
		ll cnt_adj = T1[fr].size();
		ll adj;
		for(int i = 0; i < cnt_adj; i++){
			adj = T1[fr][i].F;
			ll d = ch[fr] + T1[fr][i].S + T2[fr][i].S;
			if(d < ch[adj]){
				st.erase({ch[adj], adj});
				ch[adj] = d;
				st.insert({ch[adj], adj});
			}
		}
	}
	
	ll sc = 1;
	DFS(sc, -1);
	sp[sc][0] = sc;
	dp[sc][0][0][0] = 0;
	dp[sc][0][0][1] = ch[sc];
	dp[sc][0][1][0] = ch[sc];
	dp[sc][0][1][1] = 0;
	
	for(int i = 1; i < LOG; i++){
		for(int j = 1; j <= n; j++){
			ll p = sp[j][i - 1];
			sp[j][i] = sp[p][i - 1];
			for(int x = 0; x < 2; x++) for(int y = 0; y < 2; y++){
				for(int m = 0; m < 2; m++){
					dp[j][i][x][y] = min({dp[j][i][x][y], dp[j][i - 1][x][m] + dp[p][i - 1][m][y]});
				}
			}
		}
	}
	ll Q;
	cin >> Q;
	
	for(int i = 0; i < Q; i++){
		cin >> a >> b;
		node u, v;
		u.id = (a + 1) / 2;
		v.id = (b + 1) / 2;
		
		if(a % 2 == 0){
			u.d1 = 0;
			u.d0 = ch[(a + 1) / 2];
		} else {
			u.d0 = 0;
			u.d1 = ch[(a + 1) / 2];
		}
		
		if(b % 2 == 0){
			v.d1 = 0;
			v.d0 = ch[(b + 1) / 2];
		} else {
			v.d0 = 0;
			v.d1 = ch[(b + 1) / 2];
		}
		cout << dis(u, v) << '\n';
	}
	
	return 0;
}


/*
5
3 6 15 4 9
1 2 5 4
2 3 5 7
1 4 1 5
1 5 2 1
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