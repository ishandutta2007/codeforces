#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll Mod = 1000000007LL;
const int Maxn = 1e6 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

stack<ll> st;
ll a[Maxn], v[Maxn], l[Maxn];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, w;
	cin >> n >> w;
	w +=2;
	int m;
	for(int j = 0; j < n; j++){
		cin >> m;
		for(int i = 1; i <= m; i++) cin >> a[i];
		a[0] = 0;
		a[m + 1] = 0; 
		m += 2;
		a[m] = Inf;
		while(!st.empty()) st.pop();
		st.push(m);
		for(int i = m - 1; i>=0;i--){
			while(a[st.top()] < a[i]) st.pop();
			l[i] = st.top();
			st.push(i);
		}
		int k = w - m + 1;
		int al = w - m;
		int la = -1;
		//l[m - 1] = w + 10;
		for(int i = 0; i < m; i++){
			//if(j!=1) continue;
			//cerr << la << ' ' ;
			if(l[i] == m) l[i] = w + 10;
			int r = min(l[i] - 1, i + k - 1LL);
			if(r <= la) continue;
			v[la + 1] += a[i];
			v[r + 1] -= a[i]; 
			
			la = r;
			//cerr << la << ' ';
		}
		//cerr << '\n';
	}
	ll sm = 0;
	for(int i = 0; i < w - 1; i++){
		sm += v[i];
		if(i) cout << sm << ' ';
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