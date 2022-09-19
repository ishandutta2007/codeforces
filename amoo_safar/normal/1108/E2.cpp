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

ll n, m, a[MAXN], b[MAXN];
pll sg[MAXN];
vector<ll> st[MAXN], en[MAXN];
multiset<ll> ms;
multiset<ll>::iterator it;


ll fl = 0, del = 1000400, mn = INF;
ll cnt[2000800];

void ins(ll y){
	cnt[del + y] ++;
	mn = min(mn, y);
}

ll gm(){
	return mn;
}

void add(ll i, ll v){
	for(int x = sg[i].F; x <= sg[i].S; x++){
		if(v == 1){
			cnt[del + b[x]] --;
			if(cnt[del + b[x]] == 0 and b[x] == mn) mn ++;
			b[x] ++;
			cnt[del + b[x]] ++;
		} else {
			mn = min(mn, b[x] - 1);
			cnt[del + b[x]] --;
			b[x]--;
			cnt[del + b[x]] ++;
		}
	}
}

void build(ll x){
	for(auto seg : st[x]) add(seg, 1);
	for(auto seg : en[x - 1]) add(seg, -1);
}

vector<ll> an;

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		b[i] = a[i];
	}
	for(int j = 1; j <= m; j++){
		cin >> sg[j].F >> sg[j].S;
		st[sg[j].F].pb(j);
		en[sg[j].S].pb(j);
	}
	
	for(int i = 1; i <= n; i++) ins(b[i]);
	for(int i = 1; i <= m; i++) add(i, -1);
	fl = 1;
	//debug("fha");
	
	ll res, ans = -1;
	ll ind = -1;
	for(int i = 1; i <= n; i++){
		build(i);
		res = a[i] - gm();
		if(res > ans){
			ans = res;
			ind = i;
		}
	}
	
	
	cout << ans << '\n';
	for(int i = 1; i <= m; i++){
		if((ind < sg[i].F) or (sg[i].S < ind)) an.pb(i);
	}
	cout << an.size() << '\n';
	for(auto x : an) cout << x << " ";
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