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

ll mul(ll a, ll b){
	return (a * b) % Mod;
}
ll bin_pow(ll b, ll p){
	ll res = 1;
	for(int j = 1, pw = b; j <= p; j <<= 1, pw = mul(pw, pw)) if(p & j) res = mul(res, pw);
	return res;
}
ll inv(ll x){
	return bin_pow(x, Mod - 2);
}
ll f[Maxn], iv[Maxn];

ll nCr(ll n, ll r){
	if((r < 0) || (n < r)) return 0;
	return mul(f[n], mul(iv[r], iv[n - r]));
}

ll a[Maxn];
vector< pair<ll, pll> > Q;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	f[0] = 1;
	iv[0] = 1;
	for(int i = 1; i < Maxn; i++) f[i] = mul(f[i - 1], i), iv[i] = inv(f[i]);
	ll ans = 0;
	
	ll n, T;
	cin >> n >> T;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++){
		T -= a[i];
		if(T < 0) break;
		Q.pb({ bin_pow(2, n - i), {min((ll) i, T),i} });
	}
	ll st = -1;
	pll nw; ll sm = 0;
	for(auto x : Q){
		//cerr << x.F << " " << x.S.F << " " << x.S.S << '\n';
		if(x.S.F == x.S.S) ans += mul(x.F, bin_pow(2, x.S.F));
		else if(st == -1){
			nw = x.S;		
			st = 1;
			sm = 0;
			for(int i = 0; i <= x.S.F; i++) sm = (sm + nCr(x.S.S, i)) % Mod;
		
			ans += mul(x.F, sm);
		} else {
			while(nw.S < x.S.S){
				sm = (sm + sm - nCr(nw.S, nw.F)) % Mod;
				nw.S ++;
			}
			while(nw.F > x.S.F){
				sm -= nCr(nw.S, nw.F);
				sm %= Mod;
				nw.F --;
			}
			
			ans += mul(x.F, sm);
		}
		ans %= Mod;
	}
	ans += Mod;
	ans %= Mod;
	cout << mul(ans, inv(bin_pow(2, n)));
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