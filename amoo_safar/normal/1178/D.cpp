#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll Mod = 998244353LL;
const int Maxn = 1e3 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

bool P(ll x){
	if(x == 1) return false;
	for(int i = 2; i < x; i++) if(x % i == 0) return false;
	return true;
}
bool p[3000];

vector<ll> C[Maxn];
vector<pll> E;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll cnt = 0;
	for(int i = 2; i <= 2000; i++) p[i] = P(i);
	
	ll n;
	cin >> n;
	if(n == 8){
		cout << "13\n1 2\n1 3\n2 3\n1 4\n2 4\n1 5\n2 5\n1 6\n2 6\n1 7\n1 8\n5 8\n7 8";
		return 0;
	}
	if(n == 4){
		cout << "5\n1 2\n1 3\n2 3\n2 4\n3 4";
		return 0;
	}
	ll np=n;
	for(int i = n; i <= 2000; i++) if(p[i]){
		np = i;
		break;
	}
	//cerr << np << '\n';
	ll x = 0;
	for(int i = 1; i <= n; i+= 3){
		ll r = i + 2;
		if(r > n) continue;
		if(r + 3 > n) r = n;
		for(int k = i; k <= r; k ++){
			C[x].pb(k);
		}
		for(int k = 0; k < C[x].size(); k++){
			E.pb({C[x][k], C[x][(k + 1) % (C[x].size())]});
		}
		x++;
	}
	ll del = np - n;
	for(int i = 0; i < x; i++){
		if(del == 0) break;
		E.pb({C[i].back(),C[(i + 1) % x][0]});
		del --;
	}
	cout << E.size() << '\n';
	for(auto x : E) cout << x.F << " " << x.S << '\n';
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