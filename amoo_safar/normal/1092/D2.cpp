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

ll a[MAXN];
ll le[MAXN], ri[MAXN];
stack<ll> st;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	a[0] = INF;
	a[n + 1] = INF;
	st.push(0);
	for(int i = 1;i <=n;i++){
		//debug(i);
		while(a[st.top()] <= a[i]) st.pop();
		le[i] = st.top();
		st.push(i);
	}
	while(st.size()) st.pop();
	
	st.push(n + 1);
	for(int i = n;i >= 1;i--){
		while(a[st.top()] <= a[i]) st.pop();
		ri[i] = st.top();
		st.push(i);
	}
	
	//for(int i =1;i<=n;i++) cerr << ri[i] << " ";
	//cerr << '\n';
	ll len;
	ll mx = *max_element(a + 1, a + n + 1);
	for(int i = 1;i<=n;i++){
		len = (ri[i] - le[i] - 1);
		//debug(i);
		if((len % 2 == 1) and (mx != a[i])) return cout << "NO", 0;
	}
	cout << "YES";
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