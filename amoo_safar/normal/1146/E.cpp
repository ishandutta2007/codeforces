#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " = " << x << '\n'; 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 1e9 + 7;
const ll MAXN = (ll) 2e5 + 10;
const ll N = 1e5 + 100;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

vector<pll> ds;
ll lst[MAXN], t[MAXN];

vector<pair<char, ll>> Q;

ll cnt[MAXN];

ll a[MAXN];

int main(){
	ll n, q;
	cin >> n >> q;
	for(int i = 0; i < n; i++) cin >> a[i];
	char s;
	ll x;
	for(int i = 0; i < q; i++){
		cin >> s >> x;
		Q.pb({s, x});
	}
	ll T = 1, ab;
	for(auto que : Q){
		ab = abs(que.S);
		
		if(que.F == '<'){
			if(que.S > 0){
				ds.pb({ab - 1, T});
				lst[ab] = T; 
				t[ab] = 1;
			} else{
				lst[ab + 1] = T;
				t[ab + 1] = 1;
			}
		} else {
			if(que.S < 0){
				ds.pb({ab - 1, T});
				lst[ab] = T; 
				t[ab] = -1;
			} else {
				lst[ab + 1] = T;
				t[ab + 1] = -1;
			}
		}
		
		T++;
		//debug(T);
	}
	//debug("A");
	for(int i = 1; i < N; i++){
		if(lst[i - 1] > lst[i]){
			lst[i] = lst[i - 1];
			t[i] = t[i - 1];
		}
	}
	//debug("S");
	lst[N] = INF;
	ll un = 1;
	for(auto que : ds){
		while(lst[un] <= que.S) un ++;
		cnt[min(que.F, un - 1)] ++;
		
	}
	for(int i = N - 1; i >= 0; i--){
		cnt[i] += cnt[i + 1];	
	}
	//debug(ds.size());
	
	for(int i = 0; i < n; i++){
		ab = abs(a[i]);
		if(t[ab] == 1) a[i] = ab;
		if(t[ab] == -1) a[i] = -ab;
		//if(t[ab] != 0) debug(ab);
		if(cnt[ab] % 2 == 1) a[i] = -a[i];
		cout << a[i] << " ";
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