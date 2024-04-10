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
const int Maxn = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll ps[Maxn], ps2[Maxn];
ll mn0[Maxn], mn02[Maxn];
ll mx0[Maxn], mx02[Maxn];
ll mn1[Maxn], mn12[Maxn];
ll mx1[Maxn], mx12[Maxn];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	str A, B, s;
	A = "tokitsukaze"; B = "quailty";
	ll n, k;
	cin >> n >> k;
	cin >> s;
	s = '!' + s;
	for(int i = 1; i <= n; i++) ps[i] = ps[i - 1] + (s[i] - '0');
	for(int i = n; i >= 1; i--) ps2[i] = ps2[i + 1] + (s[i] - '0');
	mn0[0] = Inf;
	mn1[0] = Inf;
	mx0[0] = -1;
	mx1[0] = -1;
	
	for(ll i = 1; i <= n; i++){
		mn0[i] = mn0[i - 1];
		mn1[i] = mn1[i - 1];
		mx0[i] = mx0[i - 1];
		mx1[i] = mx1[i - 1];
		if(s[i] == '0') mn0[i] = min(i, mn0[i]);
		if(s[i] == '1') mn1[i] = min(i, mn1[i]);
		if(s[i] == '0') mx0[i] = max(i, mx0[i]);
		if(s[i] == '1') mx1[i] = max(i, mx1[i]);
	}
	mn02[n + 1] = Inf;
	mn12[n + 1] = Inf;
	mx02[n + 1] = -1;
	mx12[n + 1] = -1;
	
	for(ll i = n; i >= 1; i--){
		mn02[i] = mn02[i + 1];
		mn12[i] = mn12[i + 1];
		mx02[i] = mx02[i + 1];
		mx12[i] = mx12[i + 1];
		if(s[i] == '0') mn02[i] = min(i, mn02[i]);
		if(s[i] == '1') mn12[i] = min(i, mn12[i]);
		if(s[i] == '0') mx02[i] = max(i, mx02[i]);
		if(s[i] == '1') mx12[i] = max(i, mx12[i]);
	}
	
	
	for(int i = 1; i + k - 1 <= n; i++){
		ll res = ps[i - 1] + ps2[i + k];
		if((res == 0) || (res == n - k)) return cout << A, 0;
	}
	ll fl = 0, r1, r2;
	for(ll i = 1; i + k - 1 <= n; i++){
		ll min0 = min(mn0[i - 1], mn02[i + k]);
		ll max0 = max(mx0[i - 1], mx02[i + k]);
		ll min1 = min(mn1[i - 1], mn12[i + k]);
		ll max1 = max(mx1[i - 1], mx12[i + k]);
		
		if( min(max0 - min0, max(max1, i + k - 1) - min(i, min1) ) > k - 1 ) fl = 1;
		//if(fl == 1) cout <<i << '\n';
		//cerr << max0 << " " << mn02[i + k] << '\n';
		if( min(max1 - min1, max(max0, i + k - 1) - min(i, min0) ) > k - 1 ) fl = 1;
		//if(fl == 1) cout << i << '\n';
	}
	
	if(fl == 1) cout << "once again";
	else cout << B;
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