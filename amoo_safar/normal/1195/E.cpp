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

const ll Mod = 998244353LL;
const int Maxn = 3e3 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll t[Maxn][Maxn];
ll m1[Maxn][Maxn];
ll m2[Maxn][Maxn];
deque<ll> deq;
ll OK(){
	while(!deq.empty()) deq.pop_back();
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m, a, b;
	cin >> n >> m >> a >> b;
	ll g, x, y, z;
	cin >> g >> x >> y >> z;
	for(int i = 0 ; i < n * m; i++){
		t[i/m][i%m] = g;
		g = (x*g + y) % z;
	}
	OK();
	for(int i = 0; i < n; i++){
		OK();
		for(int j = 0; j < m; j++){
			if(!deq.empty()) if(deq.front() == j - b) deq.pop_front();
			
			while(!deq.empty()){
				if(t[i][deq.back()] >= t[i][j]) deq.pop_back();
				else break;
			}
			deq.pb(j);
			m1[i][j] = t[i][deq.front()];
		}
	}
	
	
	OK();
	for(int i = 0; i < m; i++){
		OK();
		for(int j = 0; j < n; j++){
			if(!deq.empty()) if(deq.front() == j - a) deq.pop_front();
			
			while(!deq.empty()){
				if(m1[deq.back()][i] >= m1[j][i]) deq.pop_back();
				else break;
			}
			deq.pb(j);
			m2[j][i] = m1[deq.front()][i];
		}
	}
	ll S = 0;
	for(int i = 0 ; i < n; i++){
		for(int j = 0 ; j < m; j++){
			//cerr << m2[i][j] << " ";
			if((i >= a- 1)&&(j >= b - 1) ) S += m2[i][j];
		}
		//cerr << '\n';
	}
	cout << S << '\n';
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