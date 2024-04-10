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

vector<pll> rec;
ll mx[12];
ll out[Maxn];
vector<ll> A, B;


int Main(){
	ll n;
	cin >> n;
	
	rec.clear();
	str s;
	cin >> s;
	//ll n = s.size();
	for(int i = 0; i < n; i++){
		rec.pb({s[i] - '0', -i});
	}
	memset(mx, -1, sizeof mx);
	fill(out, out + n, 2);
	
	sort(all(rec));
	for(auto x : rec){
		bool fl = true;
		ll ind = -x.S;
		for(int i = 0; i < x.F; i++) if(mx[i] > ind) fl = false;
		if(!fl) break;
		mx[x.F] = max(mx[x.F], ind);
		out[ind] = 1;
	}
	A.clear();
	for(int i = 0 ; i< n; i++)if(out[i] == 1) A.pb(s[i] - '0');
	for(int i = 0 ; i< n; i++)if(out[i] == 2) A.pb(s[i] - '0');
	for(int i = 0 ; i < n-1 ; i++) if(A[i] > A[i + 1]) return cout << "-\n", 0;
	for(int i = 0 ;i <n;i++) cout << out[i];
	cout << '\n';
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	while(T--) Main();
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