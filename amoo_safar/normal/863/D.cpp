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
const ll MAXN = (ll) 2e5 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

vector< pair<ll, pll> > Q;
ll a[MAXN], b[MAXN];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, q, m;
	cin >> n >> q >> m;
	for(int i = 1; i<=n;i++) cin >> a[i];
	ll t, l, r;
	for(int i = 0; i< q; i++){
		cin >> t >> l >> r;
		Q.pb({t, {l, r}});
	}
	for(int i = 0; i < m; i++) cin >> b[i];
	 
	reverse(all(Q));
	for(auto que : Q){
		t = que.F;
		l = que.S.F;
		r = que.S.S;
		if(t == 1){
			for(int i = 0; i< m;i++){
				if( b[i] < l or r < b[i]) continue;
				if(b[i] == l) b[i] = r;
				else b[i]--;
			}
		} else {
			for(int i = 0; i< m;i++){
				if( b[i] < l or r < b[i]) continue;
				b[i] = l + r - b[i];
			}
		}
	}
	for(int i=0;i<m;i++) cout << a[b[i]] << " ";
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