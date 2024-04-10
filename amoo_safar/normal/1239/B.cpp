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
const int Maxn = 3e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll v(char x){
	if(x == '(') return 1;
	return -1;
}
ll ps[Maxn];

ll ps2[Maxn];
ll calc(str t){
	ll n = t.size() - 1;
	ps2[0] = 0;
	for(int i = 1; i <= n; i++) ps2[i] = ps2[i - 1] + v(t[i]);
	ll res = 0;
	ll mn = *min_element(ps2 + 1, ps2 + n + 1);
	for(int i = 1; i <= n; i++) res += (mn == ps2[i]);
	return res;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	str s;
	cin >> s;
	ps[0] = 0;
	for(int i = 1; i <= n; i++) ps[i] = ps[i- 1] + v(s[i - 1]);
	s = '!' + s;
	
	if(ps[n] != 0) return cout << "0\n1 1\n", 0;
	ll ans = 0;
	ll L = 1, R = 1;
	ll mn = *min_element(ps + 1, ps + n + 1);
	for(int i = 1; i <= n; i++) ans += (ps[i] == mn);
	ll DDD  = ans;
	set<pll> st;
	ll ls = -1;
	ll cnt = 0;
	ll rs;
	for(int i = 1; i <= n; i++){
		if(s[i] == '('){
			st.insert({cnt, i});
		} else {
			while(!st.empty()){
				if(st.begin() -> S <= ls) st.erase(st.begin());
				else {
					rs = cnt - (st.begin() -> F);
					if(rs > ans){
						ans = rs;
						L = st.begin() -> S;
						R = i;
					}
					break;
				}
			}
		}
		if(ps[i] == mn + 1) cnt ++;
		if(ps[i] == mn) ls = i;
	}
	st.clear();
	ls = -1;
	cnt = 0;
	for(int i = 1; i <= n; i++){
		if(s[i] == '('){
			st.insert({cnt, i});
		} else {
			while(!st.empty()){
				if(st.begin() -> S <= ls) st.erase(st.begin());
				else {
					rs = DDD + cnt - (st.begin() -> F);
					if(rs > ans){
						ans = rs;
						L = st.begin() -> S;
						R = i;
					}
					break;
				}
			}
		}
		if(ps[i] == mn + 2) cnt ++;
		if(ps[i] == mn || ps[i] == mn + 1) ls = i;
	}
	str t;
	if(mn + 1 <= 0){
		t = s;
		ll fs = -1;
		for(int i = 1; i <= n; i++)
			if(ps[i] == mn){
				fs = i;
				break;
			}
		ll ss;
		for(int i = 1; i <= n; i++)
			if(ps[i] == mn){
				ss = i;
			}
			
		swap(t[fs], t[ss + 1]);
		rs = calc(t);
		if(rs > ans){
			ans = rs;
			L = fs;
			R = ss + 1;
		}
	}
	
	if(mn + 2 <= 0){
		t = s;
		ll fs = -1;
		for(int i = 1; i <= n; i++){
			if(s[i] == ')'){
				fs = i;
			}
			
			if(ps[i] == mn || ps[i] == mn + 1){
				break;
			}
		}
		ll ss = -1;
		for(int i = n; i >= 1; i--){
			
			if(ps[i] == mn || ps[i] == mn + 1){
				break;
			}
			if(s[i] == '('){
				ss = i;
			}
		}
		if(ss != -1 && fs != -1){
		swap(t[fs], t[ss]);
		rs = calc(t);
		if(rs > ans){
			ans = rs;
			L = fs;
			R = ss;
		}
		}
	}
	cout << ans << '\n' << L << " " << R << '\n';	
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