#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 2e5 + 10;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

ll a[MAXN];
ll b[12][MAXN];


map<ll,ll> ma;


ll seg(ll x){
	return (x+1)*x / 2;
}

ll c[MAXN];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n, m;
	cin >> n >> m;
	ll v;
	for(int i = 0;i<n;i++){
		cin >> v;
		ma[v] = i+1;
	}
	for(int j = 1;j<m;j++){
		for(int i = 0;i<n;i++){
			cin >> v;
			b[j][i] = ma[v];
		}
	}
	for(int j = 1;j<m;j++){
		for(int i = 1;i<n;i++){
			if(b[j][i] != b[j][i-1] + 1){
				c[b[j][i-1]] = 1;
			}
		}
		c[b[j][n-1]] = 1;
	}
	//for(int i =1;i<=n;i++) cout << c[i] << " ";
	//cout << endl; 
	ll ans = 0;
	ll t = 1;
	for(int i = 1; i < n;i++){
		if(c[i] == 0){
			t++;
		}else{
			ans += seg(t);
			//debug(t);
			t =1 ;
		}
	}
	
	
	cout << ans + seg(t);
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