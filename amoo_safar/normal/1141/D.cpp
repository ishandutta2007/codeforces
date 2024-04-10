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

const ll MOD = (ll) 1e9 + 7;
const ll MAXN = (ll) 4e5 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

map<ll, vector<pll>> mp;
ll a[MAXN];
ll ps[MAXN];
ll d[MAXN];//ans[MAXN];
//ll mn[MAXN]
ll cnt[MAXN];

ll num(char c){
	if(c == '?') return 0;
	return c -'a' + 1;
}

vector<ll> A[30], B[30];

vector<pll> ans;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	str l, r;
	cin >> l >> r;
	for(int i = 0; i< n;i++){
		A[num(l[i])].pb(i + 1);
		B[num(r[i])].pb(i + 1);
	}
	for(int i = 1; i < 30;i++){
		while(A[i].size() > 0 and B[i].size() > 0){
			ans.pb({A[i].back(), B[i].back()});
			A[i].pop_back();
			B[i].pop_back();
		}
		while(A[0].size() > 0 and B[i].size() > 0){
			ans.pb({A[0].back(), B[i].back()});
			A[0].pop_back();
			B[i].pop_back();
		}
		while(A[i].size() > 0 and B[0].size() > 0){
			ans.pb({A[i].back(), B[0].back()});
			A[i].pop_back();
			B[0].pop_back();
		}
	}	
	while(A[0].size() > 0 and B[0].size() > 0){
			ans.pb({A[0].back(), B[0].back()});
			A[0].pop_back();
			B[0].pop_back();
		}
	cout << ans.size() << '\n';
	for(auto x : ans) cout << x.F << " " << x.S << '\n';
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