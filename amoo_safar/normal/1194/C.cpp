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
const int Maxn = 5e4 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll cnt1[30], cnt2[30], cnt3[30];

int num(char x){
	return x - 'a';
}

int MAIN(){
	memset(cnt1, 0, sizeof cnt1);
	memset(cnt2, 0, sizeof cnt2);
	memset(cnt3, 0, sizeof cnt3);
	str s, t, p;
	cin >> s >> t >> p;
	for(auto x : s) cnt1[num(x)] ++;
	for(auto x : t) cnt2[num(x)] ++;
	for(auto x : p) cnt3[num(x)] ++;
	ll po = 0;
	for(auto x : t){
		if(po == s.size()) break;
		if(x == s[po]) po ++;
	}
	if(po != s.size()) return cout << "NO\n", 0;
	for(int i = 0 ; i < 28; i++){
		//cerr << i << ":i" << '\n';
		if(cnt2[i] - cnt1[i] > cnt3[i]){
			//cerr << i << "as" << '\n';
			return cout << "NO\n", 0;
		}
	}
	cout << "YES\n";
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	while(T--){
		MAIN();
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