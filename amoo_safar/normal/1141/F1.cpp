
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll MOD = (ll) 1e9 + 7;
const ll MAXN = (ll) 2e3 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

map<ll, vector<pll>> mp;
ll a[MAXN];
ll ps[MAXN];
ll d[MAXN], ans[MAXN];
ll mn[MAXN];
ll cnt[MAXN];
ll dp[MAXN], p[MAXN], t[MAXN];
vector<pll> now, an, ban;
set<ll> st;


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	ps[0] = 0;
	for(int i = 1; i <= n; i++) ps[i] = a[i] + ps[i - 1];
	for(int l = 1; l <= n; l++){
		for(int r = l; r <= n; r++){
			mp[ps[r] - ps[l - 1]].pb({l, r});
		}
	}
	ll ans = -1;
	fill(mn, mn + MAXN, -INF);
	for(auto x : mp){
		ll sm = x.F;
		
		now.clear();
		for(auto seg : x.S) now.pb(seg);
		st.clear();
		for(auto seg : now){
			st.insert(seg.F);
			st.insert(seg.S);
			st.insert(seg.S - 1);
			st.insert(seg.F - 1);
			mn[seg.S] = max(mn[seg.S], seg.F);
		}
		dp[0] = 0;
		ll mx = 0, ind = 0;
		for(auto x : st){
			if(x == 0) continue;
			if(mn[x] == -INF){
				dp[x] = mx;
				p[x] = ind;
				continue;
			}
			if(mx >= dp[mn[x] - 1] + 1){
				dp[x] = mx;
				p[x] = ind;
			} else {
				dp[x] = dp[mn[x] - 1] + 1;
				p[x] = mn[x] - 1;
			}
			if(dp[x] > mx){
				mx = dp[x];
				ind = x;
			}
		}
		an.clear();
		ll po = *(st.rbegin());
		while(po > 0){
			if(sm == -5) {
				debug(po);
			}
			ll nx = p[po];
			if(dp[po] == dp[nx] + 1){
				an.pb({nx + 1, po});
			}
			po = nx;
		}
		if(sm == -5){
			debug(p[2]);
			debug(dp[2]);
			debug(mn[2]);
		}
		if(an.size() > ban.size()){
			ban.clear();
			debug(sm);
			for(auto y : an) ban.pb(y);
		}
		
		// reset
		for(auto x : st){
			mn[x] = -INF;
		}
	}
	cout << ban.size() << '\n';
	for(auto seg : ban) cout << seg.F << " " << seg.S << '\n';
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